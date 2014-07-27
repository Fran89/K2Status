#include "messagercv.h"

MessageRcv::MessageRcv(QObject *parent) :
    QObject(parent)
{
    connect(this,SIGNAL(LastServerBeat(QTcpSocket*,Config*,bool)),
            this,SLOT(echo_Heartbeat(QTcpSocket*,Config*,bool)));
}

void MessageRcv::ListenMessage(QTcpSocket *sock, Config *Conf, bool Debug) {

    static int    state;
    static char   chr, lastChr;
    static int    nr;
    static qint32 nchar;                     /* counter for msg buffer (esc's removed) */
    static char   startCharacter=STX;        /* ASCII STX characer                     */
    static char   endCharacter=ETX;          /* ASCII ETX character */
    static char   escape=ESC;                /* our escape character */
    static qint32 inchar;                    /* counter for raw socket buffer (w/esc) */
    QByteArray    temp;
    // time_t       LastBeat; Maybe in the future


    emit updatetxtbox(QString("Message Thread Started"));

    //NOT WORKING!!
    emit LastServerBeat(sock,Conf,Debug); //Beat our Heart Once


    state=SEARCHING_FOR_MESSAGE_START; /* we're initializing */

    /* Start of New code Section DK 11/20/97 Multi-byte Read
       Set inchar to be nr-1, so that when inchar is incremented, they will be
           the same and a new read from socket will take place.
       Set chr to 0 to indicate a null character, since we haven't read any yet.
       Set nchar to 0 to begin building a new MsgBuffer (with escapes removed).
    */
    inchar = -1;
    nr     =  0;
    chr    =  0;
    nchar  =  0;  /* added 980209:LDD */
    /* End of New code Section */

    /* Working loop: receive and process messages
     ********************************************/
    /* We are either (0) initializing: searching for message start
                   (1) expecting a message start: error if not
                   (2) assembling a message.
    The variable "state' determines our mood */

    while(1) { /* loop over bytes read from socket */

        /* Get next char operation */
        if (++inchar == nr) {
            temp.clear();
            while (temp.size()==0){
                /* Read from socket operation */
                temp = sock->read(INBUFFERSIZE);
            }
            nr = temp.size();
            inchar=0;
        /* End of Read from socket operation */
        }
        lastChr=chr;
        chr=temp[inchar];
        /* End of Get next char operation */

        /* Initialization */
        /******************/
        if (state==SEARCHING_FOR_MESSAGE_START) {
            /* throw all away until we see a naked start character */
            /* Do we have a real start character?
             *************************************/
            if ( lastChr!=escape && chr==startCharacter) {
                state=ASSEMBLING_MESSAGE;  /*from now on, assemble message */
                continue;
            }
        }

        /* Confirm message start */
        /*************************/
        if (state==EXPECTING_MESSAGE_START) { /* the next char had better be a start character - naked, that is */
            /* Is it a naked start character?
             *********************************/
            if ( chr==startCharacter &&  lastChr != escape) { /* This is it: message start!! */
                nchar=0; /* start with firsts char position */
                state=ASSEMBLING_MESSAGE; /* go into assembly mode */
                continue;
            }
            else{ /* we're eating garbage */
                emit updatetxtbox("import_generic: Unexpected character from client. Re-synching");
                state=SEARCHING_FOR_MESSAGE_START; /* search for next start sequence */
                MsgBuf.clear();
                continue;
            }
        }

        /* In the throes of assembling a message */
        if (state==ASSEMBLING_MESSAGE) {

            /* Is this the end?
             *******************/
            if (chr==endCharacter){ /* naked end character: end of the message is at hand */

                /* We have a complete message */
                /*****************************/
                MsgBuf[nchar]=0; /* terminate as a string */

                if(MsgBuf.contains(Conf->getSendHSQ().toLocal8Bit())){ /* Server's heartbeat */
                    if(Debug) {
                        emit updatetxtbox(QString("import_generic: Received heartbeat"));
                    }
                    // LastBeattime = time(0); /* note time of heartbeat */
                    state=EXPECTING_MESSAGE_START; /* reset for next message */

                    //THIS IS STILL NOT WORKING
                    emit echo_Heartbeat(sock, Conf, Debug);
                }
                else {
                    /* got a non-heartbeat message */
                    if(Debug) {
                        emit updatetxtbox(QString("import_generic: Received non-heartbeat"));
                    }
                    //LastBeat = time(0); /* note time of heartbeat */
                    /* This is not a genuine heartbeat, but our major concern is that the
                     * export module on the other end is still alive, and any message that
                     * we receive should indicate life on the other side(in a non occult
                     * kind of way).
                     * */
                    emit ReturnMessage(MsgBuf.mid(9)); /* process the message via user-routine */
                }
                state=EXPECTING_MESSAGE_START;
                MsgBuf.clear();
                continue;
            }
            else {
                /* process the message byte we just read: we know it's not a naked end character*/
                /********************************************************************************/
                /* Escape sequence? */

                if (chr==escape) {
                    /*  process the escape sequence */

                    /* Read from buffer
                     * *******************/
                    /* Get next char operation */
                    if (++inchar == nr) {
                        /* Read from socket operation */
                        temp.clear();
                        while (temp.size()==0){
                            /* Read from socket operation */
                            temp = sock->read(INBUFFERSIZE);
                        }
                        nr = temp.size();
                        inchar=0;
                        /* End of Read from socket operation */
                    }
                    lastChr=chr;
                    chr=temp[inchar];
                    /* End of Get next char operation */

                    if( chr != startCharacter && chr != endCharacter && chr != escape) {
                        /* bad news: unknown escape sequence */
                        emit updatetxtbox(QString("import_generic: Unknown escape sequence in message. Re-synching"));
                        state=SEARCHING_FOR_MESSAGE_START; /* search for next start sequence */
                        MsgBuf.clear();
                        continue;
                    }
                    else { /* it's ok: it's a legit escape sequence, and we save the escaped byte */
                        MsgBuf.append(chr); if(nchar>2100) goto freak; /*save character */
                        continue;
                    }
                }

                /*  Naked start character? */
                if (chr==startCharacter) {
                    /* bad news: unescaped start character */
                    emit updatetxtbox(QString("import_generic: Unescaped start character in message. Re-synching"));
                    state=SEARCHING_FOR_MESSAGE_START; /* search for next start sequence */
                    MsgBuf.clear();
                    continue;
                }

                /* So it's not a naked start, escape, or a naked end: Hey, it's just a normal byte */
                MsgBuf.append(chr); if(nchar>2100) goto freak; /*save character */
                continue;

                freak: { /* freakout: message won't fit */
                    emit updatetxtbox(QString("import_generic: receive buffer overflow"));
                    state=SEARCHING_FOR_MESSAGE_START; /* initialize again */
                    MsgBuf.clear();
                    nchar=0;
                    continue;
                }
            } /* end of not-an-endCharacter processing */
        } /* end of state==ASSEMBLING_MESSAGE processing */
    }  /* end of loop over characters */
}


// Send HeartBeat
void MessageRcv::echo_Heartbeat(QTcpSocket *sock, Config* Conf, bool Debug){

    int INSTID = Conf->getINSTID();
    int Module = 0;
    int Type   = 3;


    QByteArray HeartBeat;
    HeartBeat.append(STX);
    HeartBeat.append(QString("%1%2%3").arg(INSTID,3).arg(Module,3).arg(Type,3));
    HeartBeat.append(Conf->getMyHSQ());
    HeartBeat.append(ETX);


    sock->write(HeartBeat.data());

    if(Debug) {
        //emit ReturnMessage(HeartBeat);
        emit updatetxtbox(QString("import_generic: SocketHeartbeat sent to export"));
    }
}

