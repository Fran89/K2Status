/*
 *   THIS FILE IS UNDER RCS - DO NOT MODIFY UNLESS YOU HAVE
 *   CHECKED IT OUT USING THE COMMAND CHECKOUT.
 *
 *    $Id: nkwhdrs.h 1768 2005-03-24 23:35:56Z kohler $
 *
 *    Revision history:
 *     $Log$
 *     Revision 1.3  2005/03/24 23:35:56  kohler
 *     Added network code and location code to CHANNEL_RW_PARMS structure.  WMK
 *
 *     Revision 1.2  2000/08/30 17:34:00  lombard
 *     See ChangeLog entry for 30 August 2000
 *
 *     Revision 1.1  2000/05/04 23:48:37  lombard
 *     Initial revision
 *
 *
 *
 */
/* kwhdrs.h   Combined K2 & Mt. Whitney header definition
              also Tag definition & Frame header definition  */

/*   2/18/99 -- [ET]  Modified version with 'FIX_8BYTES_K2RW' fix */
#include<QtGlobal>
/**************************************************************

REVISION HISTORY:

Version 1.00 (July 5, 1994)
-------------------------
Initial release with support for 12 channels.

Version 1.10 (August 25, 1994)
----------------------------
NOTE: all structure sizes and previous parameter offsets remain the same.

Used expansion space in CHANNEL_RW_PARMS to add the following:
   unsigned short sensorSerialNumberExt;  (high word of sensor serial number)
   float resp1,resp2,resp3,resp4,resp5,resp6; (sensor response)

Used expansion space in MISC_RW_PARMS to add the following:
   unsigned char minBatteryVoltage; (minimum battery voltage x 10)

Added new sensor code definitions for FBA 4g, 2g, 1g, 0.5g, 0.25g and 0.1g
for parameter CHANNEL_RW_PARMS.sensorType.  The code definitions are
   #define SENSOR_FBA_4G 11
   #define SENSOR_FBA_2G 12
                etc.

Changed MISC_RO_PARMS.batteryVoltage type from unsigned short to signed
short.  MISC_RO_PARMS.batteryVoltage has negative value if charging.
(For example, MISC_RO_PARMS.batteryVoltage = -130 indicates 13.0 V
and charging).

Redefined the meaning of STREAM_RW_PARMS.filterFlag.
Redefined the meaning of MODEM_RW_PARMS.flags.
Changed TIMING_RW_PARMS.gpsTurnOnInterval from hours to minutes.

New parameters:
   MISC_RO_PARMS.temperature
   MISC_RO_PARMS.restartSource
   MISC_RW_PARMS.networkFlag
   FRAME_HEADER.msec
   STREAM_RO_PARMS.nscans
   STREAM_RO_PARMS.startTimeMsec
   STREAM_RO_PARMS.triggerTimeMsec
   CHANNEL_RO_PARMS.aqOffset

   Added on 8/26/94:
   TIMING_RO_PARMS.gpsLongitude
   TIMING_RO_PARMS.gpsLatitude
   TIMING_RO_PARMS.gpsAltitude

   Added 9/9/94:
   MODEM_RW_PARMS.flags: added more definitions for bit fields

   Added 10/11/94:
   TIMING_RO_PARMS.dacCount


  10/20/94 make note to CORRECT name: 
   STREAM_RW_PARMS.triggerThreshold & .detriggerThreshold ACTUALLY 'VOTES TO TRIGGER' !!!!! 

   11/18/94   make header 24 channels -- to check arrays --  OK! 
  
   Version 1.20 (28 November 1994) 
 --------------------------------------- 
   11/29/94  make header 18 channels - Mt.Whitney -- for now 
                MAX_CHANNELS 18 
                FRAME_HEADER_TYPE:  FHT16 3   one 16-bit channel bit map 
                                    FHT24 4     "        "                + byte bit map 
                PARAMETER_VERSION 120 
 --------------------------------------------------------- 



  Version 1.20 Mt Whit / 1.30 K2 (January 30, 1995) (March 3, 1995) 
  ---------------------------- 
      Moved MTWHITNEY define here from mt.h to allow preprocessing 
      for different headers for K2 and Mt Whit 
              Mt Whit:        MAX_CHANNELS                    12 -> 18 
                                      PARAMETER_VERSION               110 -> 120 
                                      FRAME_HEADER_TYPE               3 (16 ch) -> 4 (24 ch) 

      FRAME_HEADER:  Renamed 'unsigned char pad4' to 'uc channelBitMap1' to 
      support chan 17-24 (chan 1-16 are in channelBitMap) 

      MISC_RW_PARMS: added ul channel_bitmap, ul cutler_bitmap, 
      uc cutler_decimation, uc cutler_irig_type, uc cutler_protocol; 
      uc cutlerCode now just sets the baudrate; 
      reduced 'char bpad[14]' & 'int wpad[7] 
      to [10] & [3] to keep structure the same size 

      MISC_RO_PARMS: add us installedChan so QT can see how many 
      channels are installed; decreased char bytepad[5] -> [3] to 
      keep struct the same size 

      K2_ALARM: changed ui channelBitMap to ulong 

  ********************************************* 

     8/25/94  
     3/03/95   Ver 1.20/1.30  
              remove K2 File System(K2-Directory) definitions. not used  
              remove EVT_SUMMARY, not used  
              remove STATUS_INFO, not used  
              add from another .H: K2_TAG  
  
  -----------------03-05-95 06:23pm----------------- 
   3/05/95  update with 1.20/1.30 header 
            make final header, frame & tag structures = typedefs 
  --------------------------------------------------

  -----------------03-16-95 01:05pm----------------- 
   3/16/95  combined version K2 & MW headers - 12/18 channels 
  --------------------------------------------------

   ---------------------------------------------- 
   5/21/96  add Parameters to Mt. Whitney (& K2) 
            NO CHANGE IN VERSION NUMBER - REDEFINITION OF EXISTING PADS 

            STREAM_RO_PARAMS: pad[2] -> triggerBitMap, pad[1] 
            MISC_RW_PARMS: bpad[11],wpad[3] -> char siteID[17] 
            MODEM_RW_PARMS: 

              char pauseBetweenCalls   '' define '0'= random delay 5-30sec 

              from:  char bytepad[17] 
              to:    char cellShare;  '' K2 only, =0 for 1 Hz output, =1 for cell phone '' 
                     char cellOnTime;       '' in minutes '' 
                     unsigned char cellWarmupTime;  '' in seconds '' 
                     int cellStartTime[2];  '' minutes since midnight '' 
                     char bytepad[10]; 

              from:  unsigned short wordpad[7]; 
                     unsigned long dwordpad[8]; 
              to:    char calloutMsg[46]; 

  ------------------------------------------------- 


  ------------------------------------------------- 
    5/31/96  add SRT & TRIG DATA bits to  ' roParms.stream.flags' 
  ------------------------------------------------- 

   ---------------------------------------------- 
    6/10/96  change  modem-rw: 
                         int  cellStartTime[] from 2 to 5 
                         char bytepad[] from 10 to 4 

  ------------------------------------------------- 

   7/2/96  noted for CHANNEL_RO_PARAMETERS: 
              'recorded channels entered consecutively' 

   9/18/96  new k2defs.h from MERGED MCU - no changes that effect 
               kwhd1.c 
              QLCA's vhf1/2.c merged into kwhd1/2.c 
              cellShare -- NOT USED 
              REMOVE:  from formatted files: Sensor Response -- not used 
              kwhdrs.h NOT redistributed over all files 
  *************************************************************
  
   --------------------- 

   3/28/97 

  File Version 1.50: 1.40(K2) & 1.50(MW) 12/18-channel header (February 1997) 
  ------------------------------------------------------ 

    Change the following: 

    CHANNEL_RW_PARAMETERS: 

    after 'gain': 

    OUT -- 8 bytes : 

     float resp1; * sensor response; poles and zeroes * 
     float resp2; 

    IN  -- 8 bytes : 

     unsigned char triggertype;       * Type of trigger calculation  * 
                                      default = 0 = Threshold 

                                   valid: code 0h  threshold 
                                               1   sta/lta 

     unsigned char iirtrigfilter;     * coefficients for iir trigger filter * 
                                      default = 1 = B  0.1Hz to 12.5 Hz @ 200sps 

                    valid: code 0h  A 
                                1   B 
                                2   C 
                                3   D 

     unsigned char stasecondsTten;    * STA seconds * ten * 
                                       default = code 7 = 1.0 seconds 

                      valid: code 0h  0.1  store 1     Ah  1.6 store 16 
                                  1   0.2   as   2     B   1.8  as   18 
                                  2   0.3        3     C   2.0       20 
                                  3   0.4        4     D   2.5       25 
                                  4   0.5        5     E   3.0       30 
                                  5   0.6        6     F   5.0       50 
                                  6   0.8        8    10  10.0      100 
                                  7   1.0       10 
                                  8   1.2       12 
                                  9   1.4       14 

     unsigned char ltaseconds;         * LTA seconds * 
                                        default = code 4 = 60 seconds 

                                   valid: code 0h  20 
                                               1   30 
                                               2   40 
                                               3   50 
                                               4   60 
                                               5   80 
                                               6  100 
                                               7  120 

     unsigned short sta/ltaratio;    * STA/LTA trigger ratio * ten * 
                                     default = code 3 = 4 

                      valid: code 0h  1.5  store 15   7h  15 store 150 
                                  1   2     as   20   8h  20  as   200 
                                  2   3          30   9   30       300 
                                  3   4          40   A   40       400 
                                  4   6          60   B   60       600 
                                  5   8          80   C  100      1000 
                                  6  10         100 

     unsigned char sta/ltapercent;  * STA/LTA detrigger percent of trigger ratio * 
                                     default = code 3 = 40% 

                      valid: code 0h  10%  store 10 
                                  1   15    as   15 
                                  2   20         20 
                                  3   40         40 
                                  4   60         60 
                                  5  100        100 

     char bytepad1[1];        * reserved * 



    after 'alarmTriggerThreshold': 

    OUT - 16 bytes : 

     float resp3; 
     float resp4; 
     float resp5; 
     float resp6; 

    IN  - 16 bytes: 

     char bytepad[16];     * reserved * 

     ------------ 

   STREAM_RW_PARMS: 

   OUT -- 24 bytes: 

     short wordpad[4]; * for expansion * 

     long dwordpad[4]; * for expansion * 

   IN -- 24 bytes: 

     char bytepada; 
     unsigned char FilterType;        * FirB: 0 regular, 1 causal * 
     unsigned char DataFmt;           * Serial Data Stream: 0=uncompressed 
                                                       1=compressed  * 
     char Reserved; 
     short Timeout;                   * Serial Data Stream Mode:        * 
                                      *    mode 1 - 0   default    * 
                                      *         2 - 6..32767       * 
                                      *             send 'continue cmd' * 
                                      *         3 -  -1  cmd for each block * 

     unsigned short TxBlkSize;        * Serial Data Stream :           * 
                                      *  fixed @ 100 samples per block * 
     unsigned short BufferSize;       * Serial Data Stream:            * 
                                      *  size of #SSTRBUF.BIN file in disk * 
                                      *  number of 16,384 byte blocks * 
                                      *  default= 64  - 1Meg * 
     unsigned short SampleRate;       * Serial Data Stream:            * 
                                      *  fixed at 100 sps * 
     unsigned long TxChanMap;         * Serial Data Stream:            * 
                                      *  select up to 6 channels * 

     long dwordpad[2]; * for expansion * 

   ---------------- 








   Bottom Of Header Comments
****************************************************************************/

/* Type Definitions:
 *        char: 1 byte integer
 *        short: 2 byte integer
 *        float: 4 byte floating point (IEEE format)
 *        long: 4 byte integer
 *   All structures are 16-bit aligned
*/


#define FIX_8BYTES_K2RW 1         /* 8-byte fix for K2_HEADER -- see below */


#define MAX_MW_CHANNELS 18
#define VERSION_MW 150 /* =1.20 & 1.50; header version number x 100 */

#define MAX_K2_CHANNELS 12
#define VERSION_K2 140 /* = 1.00, 1.10, 1.30 & 1.40; header version number x 100 */

#define DFS_MAX_CHANNELS 3  /* =3 orig, eventually = 6 */

#define MAX_STREAMS 1
#define INSTRUMENT_CODE 9 /* for K2 */

/* SENSOR TYPE CODES */
#define SENSOR_UNKNOWN 0
#define SENSOR_ACCELERATION 1
#define SENSOR_VELOCITY 2
#define SENSOR_FBA11 10
#define SENSOR_FBA_4G 11                /* 4g FBA */
#define SENSOR_FBA_2G 12                /* 2g FBA */
#define SENSOR_FBA_1G 13                /* 1g FBA */
#define SENSOR_FBA_0_5G 14              /* 0.5g FBA */
#define SENSOR_FBA_0_25G 15             /* 0.25g FBA */
#define SENSOR_FBA_0_1G 16              /* 0.1g FBA */
#define SENSOR_FBA23 20
#define SENSOR_WR1 30

/* Voter type codes */
#define VOTER_UNDEFINED         0
#define VOTER_CHANNEL           'C'
#define VOTER_STREAM            'S'
#define VOTER_NETWORK           'N'
#define VOTER_KEYBOARD          'K'
#define VOTER_EXTERNAL          'E'
#define STREAM_K2_MAX_VOTERS (MAX_K2_CHANNELS+3) /* channels+network+keyboard+ext */
#define STREAM_MW_MAX_VOTERS (MAX_MW_CHANNELS+3) /* channels+network+keyboard+ext */

/* Restart sources for use with MISC_RO_PARMS.restartSource */
#define RESTART_UNKNOWN 0
#define RESTART_FROM_POWERSWITCH 1 /* someone flipped the power switch */
#define RESTART_FROM_COMMAND 2 /* user command to reset */
#define RESTART_FROM_WATCHDOG 3 /* watchdog caught a system crash */
#define RESTART_FROM_DSPFAILURE 4 /* DSP failure caused reset */
#define RESTART_FROM_BATTERYFAILURE 5 /* battery failure caused reset */
#define RESTART_FROM_MEMORYERROR 6 /* memory error caused reset */

/*---------------------------------------------------*/

/* Voting information */
struct VOTER_INFO {
   quint8 type; /* voter type code */
   quint8 number; /* channel number, stream number, etc. */
   qint16 weight; /* voting weight: range is -100 to 100 */
};

/*---------------------------------------------------*/

/* Channel read/write parameters */
struct CHANNEL_RW_PARMS {
#define CHANNEL_ID_LENGTH 5
   char id[CHANNEL_ID_LENGTH]; /* NULL terminated */
   char bytepad; /* for expansion */
   quint16 sensorSerialNumberExt; /* high word of serial number */
   qint16 north; /* displacement */
   qint16 east; /* displacement */
   qint16 up; /* displacement */
   qint16 altitude;
   qint16 azimuth;
   quint16 sensorType;
   quint16 sensorSerialNumber; /* low word of serial number */
   quint16 gain;  /*  only '1' defined as gain of 1 5/31/95 */

/* begin  added 3/29/97 1.40 K2 & 1.50 MTW */
   quint8 triggerType;  /* Type of trigger calculation  added headver 1.50
                                  default = 0 = Threshold

                                  valid: code 0h  threshold
                                              1   sta/lta    */

   quint8 iirTriggerFilter;  /* coefficients for iir trigger filter  ver 1.50
                                    default = 1 = B  0.1Hz to 12.5 Hz @ 200sps

                                    valid: code 0h  A
                                                1   B
                                                2   C  */



   quint8 StaSeconds;  /* STA seconds * ten   ver 1.50
                                     default = code 7 = 1.0 seconds

                    valid: code 0h  0.1  store 1     Ah  1.6 store 16
                                1   0.2   as   2     B   1.8  as   18
                                2   0.3        3     C   2.0       20
                                3   0.4        4     D   2.5       25
                                4   0.5        5     E   3.0       30
                                5   0.6        6     F   5.0       50
                                6   0.8        8    10  10.0      100
                                7   1.0       10
                                8   1.2       12
                                9   1.4       14   */

   quint8 LtaSeconds;    /* LTA seconds     ver 1.50
                                   default = code 4 = 60 seconds

                                 valid: code 0h  20
                                             1   30
                                             2   40
                                             3   50
                                             4   60
                                             5   80
                                             6  100
                                             7  120  */

   quint16 StaLtaRatio;  /* STA/LTA trigger ratio * ten  ver 1.50
                                    default = code 3 = 4

                    valid: code 0h  1.5  store 15   7h  15 store 150
                                1   2     as   20   8h  20  as   200
                                2   3          30   9   30       300
                                3   4          40   A   40       400
                                4   6          60   B   60       600
                                5   8          80   C  100      1000
                                6  10         100      */

   quint8 StaLtaPercent;  /* STA/LTA detrigger percent of trigger ratio
                                     default = code 3 = 40%         ver 1.50

                    valid: code 0h  10%  store 10
                                1   15    as   15
                                2   20         20
                                3   40         40
                                4   60         60
                                5  100        100   */

   char bytepada;
/* end 1.40 & 1./50 additions */

   float fullscale; /* volts */
   float sensitivity; /* in volts per unit (e.g., g's) */
   float damping; /* fraction of critical */
   float naturalFrequency; /* hz */
   float triggerThreshold; /* fraction of fullscale */
   float detriggerThreshold; /* fraction of fullscale */
   float alarmTriggerThreshold; /* fraction of fullscale */

/* EpiSensor addition 3/24/05 */
    float calCoil;               /* g/Volt for EpiSensor */
    quint8 range;         /* Range code for sensor: from EEPROM
                                      1=4g
                                      2=2g
                                      3=1g
                                      4=1/2g
                                      5=1/4g, etc */
    quint8 sensorgain;    /* Same, but as determined by MCU */
/* End of EpiSensor addition 3/24/05 */

/* Network and location code additions 3/24/05 */
#define NETWORK_CODE_LENGTH 3
    char networkcode[NETWORK_CODE_LENGTH];     /* Network code  */
#define LOCATION_CODE_LENGTH 3
    char locationcode[LOCATION_CODE_LENGTH];   /* Location code */
    char bytepad2[4];
/* End network and location code additions 3/24/05 */
};


/*---------------------------------------------------*/
/* Read only parameters */
/* recorded channels entered consecutivly */
struct CHANNEL_RO_PARMS {
   qint32 maxPeak; /* raw sample counts */
   quint32 maxPeakOffset; /* offset from start of file */
   qint32 minPeak;
   quint32 minPeakOffset; /* offset from start of file */
   qint32 mean; /* raw sample counts */
   qint32 aqOffset;
   qint32 dwordpad[3]; /* for expansion */
};

/*---------------------------------------------------*/

/* Stream read/write information */
struct STREAM_K2_RW_PARMS {
   quint8 filterFlag; /* BIT0 = 1 if filtered data;  NOT USED
                                BIT1 = 1 if auto FT after Event
                                BIT2 = 1 if compressed - NOT USED */
   quint8 primaryStorage; /* = 0 for drive A: ,etc. */
   quint8 secondaryStorage; /* = 1 for drive B:, etc. */
   quint8 bytepad[5]; /* for expansion */
   quint16 eventNumber; /* *NOT USED* */
   quint16 sps; /* sampling rate */
   quint16 apw; /* array propagation window, in seconds */
   quint16 preEvent; /* in seconds */
   quint16 postEvent; /* in seconds */
   quint16 minRunTime; /* in seconds */
   qint16 VotesToTrigger; /* signed number */
   qint16 VotesToDetrigger;

/* begin change 3/29/97 1.40 & 1.50 */
   char bytepada;
   quint8 FilterType;        /* 0 regular, 1 causal */
   quint8 DataFmt;
   char Reserved;
   qint16 Timeout;
   quint16 TxBlkSize;
   quint16 BufferSize;
   quint16 SampleRate;
   quint32 TxChanMap;
   qint32 dwordpad[2]; /* for expansion */
/* end change 3/29/97 1.40 & 1.50 */

   /* Voter info: one entry for each channel, network, user command */
   /* Use functions IsStreamVoter() and GetStreamVoterWeight() in
          STRMPAR.C to access the members.
   */
   struct VOTER_INFO voterInfo[STREAM_K2_MAX_VOTERS];
};


/* Stream read/write information */
struct STREAM_MW_RW_PARMS {
   quint8 filterFlag; /* BIT0 = 1 if filtered data;
                                BIT1 = 1 if auto FT after Event
                                BIT2 = 1 if compressed */
   quint8 primaryStorage; /* = 0 for drive A: ,etc. */
   quint8 secondaryStorage; /* = 1 for drive B:, etc. */
   quint8 bytepad[5]; /* for expansion */
   quint16 eventNumber; /* *NOT USED* */
   quint16 sps; /* sampling rate */
   quint16 apw; /* array propagation window, in seconds */
   quint16 preEvent; /* in seconds */
   quint16 postEvent; /* in seconds */
   quint16 minRunTime; /* in seconds */
   qint16 VotesToTrigger; /* signed number */
   qint16 VotesToDetrigger;

/* begin change 3/29/97 1.40 & 1.50 */
   char bytepada;
   quint8 FilterType;        /* 0 regular, 1 causal */
   quint8 DataFmt;
   char Reserved;
   qint16 Timeout;
   quint16 TxBlkSize;
   quint16 BufferSize;
   quint16 SampleRate;
   quint32 TxChanMap;
   qint32 dwordpad[2]; /* for expansion */
/* end change 3/29/97 1.40 & 1.50 */

   /* Voter info: one entry for each channel, network, user command */
   /* Use functions IsStreamVoter() and GetStreamVoterWeight() in
          STRMPAR.C to access the members.
   */
   struct VOTER_INFO voterInfo[STREAM_MW_MAX_VOTERS];
};


/*---------------------------------------------------*/

/* Stream read only parameters */
struct STREAM_RO_PARMS {
   quint32 startTime; /* first sample time, includes PEM */
   quint32 triggerTime;
   quint32 duration; /* in # of frames; note: frames may have different sizes */
   qint32 errors;
   qint32 flags; /* Bit 0 = 1 if functional test */
                       /* bit 1 = 1 if Sensor Response Test, SRT (& 0x03 = 0x03) */
                       /* bit 2 = 1 if recorded data = trigger data (& 0x04 = 0x04) */
   qint32 startTimeMsec;
   qint32 triggerTimeMsec;
   quint32 nscans; /* # of scans in the event */

  /* start of RW_K2_PARMS is 8 bytes too far along--don't know where */
  /*  the problem is, so taking 8 bytes away from the end of the */
  /*  RO_K2_PARMS area -- 2/18/99 -- [ET] */
#if !FIX_8BYTES_K2RW
   quint32 triggerBitMap; /* indicates first channel to trigger 5/96 */
   quint32 pad; /* for expansion */
#endif
};

/*---------------------------------------------------*/

/* Miscellaneous read/write parameters: 92 bytes */
struct MISC_RW_PARMS {
   quint16 serialNumber;
   quint16 nchannels;            /* number of channels used */
#define STN_ID_LENGTH 5
   char stnID[STN_ID_LENGTH]; /* null terminated */
#define COMMENT_LENGTH 33
   char comment[COMMENT_LENGTH]; /* NULL terminated */
   qint16 elevation; /* meters above sea level */
   float latitude; /*  degrees North */
   float longitude; /* degrees East */
   qint16 userCodes[4];                             /* 60 bytes to here */

   /* Cutler grabber */
   quint8 cutlerCode; /* 0: Cutler Off
                              * 1: 4800 baud
                              * 2: 9600 baud
                              * 3: 19200 baud
                              * 4: 38400 baud    added 1.20-1.30 
                              * 5: 57600 baud    added 1.20-1.30 
                              */

   quint8 minBatteryVoltage; /* minimum alarm battery voltage x 10 */

  /*  added 5 following parameters 3/3/95 for 1.20 MW & 1.30 K2 headers */
   quint8 cutler_decimation;     /* Cutler grabber decimation factor */
                                                                        /* valid 0=1:1(raw), 1= 1:2, 2= 1:4, 3= 1:5, 4= 1:10, 5= 1:20 */
                                                                        /* restrictions on 1:4 @ 250 sps? */
   quint8 cutler_irig_type;  /* 0:B   1:E (default)   2:H */
   quint32 cutler_bitmap;         /* Digital Field Station bit map - channels to output */
   quint32 channel_bitmap;        /* channels selected for acq storage */
   quint8 cutler_protocol; /* 0:CRLF - USGS DFS, 1:KMI/Agbabian */

   char siteID[17];    /* added 5/21/96 */

   /* Network */
   quint8 externalTrigger; /* either 1 (on) or 0 (off) */
   quint8 networkFlag; /* BIT0 = 0 (Master) or = 1 (Slave) */

};

/*---------------------------------------------------*/

/* Miscellaneous read only parameters */
struct MISC_RO_PARMS {
   quint8 a2dBits; /* A/D bits per sample; = A2DBITS */
   quint8 sampleBytes; /* bytes per sample; = 3 */
   quint8 restartSource; /* code of restart source:
                                   0 = unknown
                                   1 = power switch;
                                   2 = user command,
                                   3 = software watchdog,
                                   4 = DSP failure,
                                   5 = battery failure
                                   6 = memory error */
   char bytepad[3]; /* for expansion */

   quint16 installedChan; /* number of channels in system
                                    = (# dsp brds) * (chan per brd) */
   quint16 maxChannels; /* physical number of channels */
   quint16 sysBlkVersion; /* sys block version * 100 */
   quint16 bootBlkVersion; /* boot block version * 100 */
   quint16 appBlkVersion;  /* application block version * 100 */
   quint16 dspBlkVersion; /* DSP version * 100 */

   /* System Status */
   qint16 batteryVoltage; /* voltage * 10; negative value indicates charging */

   quint16 crc; /* 16-bit CRC of entire file, with this word set to 0xffff */
                                           /* NOTE: this parameter is not used at the moment.
              For integrity checking, the header and each frame are preceeded
              by a structure tag which contains a checksum */
   quint16 flags; /* bit 0 = 1 if DSP system error */
   qint16 temperature; /* degrees C x 10 */
   qint16 wordpad[3]; /* for expansion */

   qint32 dwordpad[4]; /* for expansion */
};

/*---------------------------------------------------*/
struct TIMING_RW_PARMS
{
   quint8 gpsTurnOnInterval; /* minutes between GPS update checking */
   quint8 gpsMaxTurnOnTime; /* max time in minutes GPS tries to lock before giving up */
   quint8 bytepad[6];
   qint16 localOffset; /* hours ahead of UTC; if this parameter is non-zero
                                                 then all times are in UTC time. If this parameter
                                                 is zero, then all times are based on local time.
                                          */
   qint16 wordpad[3];
   qint32 dwordpad[4];
};

/*---------------------------------------------------*/

struct TIMING_RO_PARMS
{
   quint8 clockSource; /* 0 = RTC from cold start
                                 1 = keyboard
                                 2 = Sync w/ ext. ref. pulse
                                 3 = Internal GPS
                                 */

   quint8 gpsStatus; /* Bit 0=1 if currently checking for presence
                                          of GPS board
                               Bit 1=1 if GPS board present
                               Bit 2=1 if error communicating with GPS
                               Bit 3=1 if failed to lock within an
                                          allotted time (gpsMaxTurnOnTime)
                               Bit 4=1 if not locked
                               Bit 5=1 when GPS power is ON
                               Bits 6,7=undefined
                             */

   quint8 gpsSOH; /* Current state of health; same as Acutime SOH code */
   quint8 bytepad[5]; /* for expansion */

   quint16 gpsLockFailCount; /* # of times GPS failed to locked within gpsMaxTurnOnTime */
   quint16 gpsUpdateRTCCount; /* # of times GPS actually updated the RTC */
   qint16 acqDelay; /* time in msec between actual A/D conversion and DSP output */
   qint16 gpsLatitude; /* latitude x 100 , degrees North */
   qint16 gpsLongitude; /* longitude x 100, degrees East */
   qint16 gpsAltitude; /* altitude in meters */
   quint16 dacCount; /* dac counts */
   qint16 wordpad; /* for expansion */
   qint16 gpsLastDrift[2]; /* in msec.; e.g. 5 = RTC was 5 msec faster than GPS */
  /*
   * From KMI support: here's what these two components mean: (PNL 7/23/00)
   * short gpsLastDrift[0] = the last measured GPS drift in mS.
   * short gpsLastDrift[1] = the previously measured GPS drift in mS.
   */

   quint32 gpsLastTurnOnTime[2]; /* time when GPS was last turned on */
   quint32 gpsLastUpdateTime[2]; /* time of last RTC update */
   quint32 gpsLastLockTime[2]; /* time of last GPS lock */
   qint32 dwordpad[4]; /* for expansion */
};

/*---------------------------------------------------*/
#define MODEM_INITCMD_LENGTH 64
#define MODEM_DIALPREFIX_LENGTH 16
#define MODEM_DIALSUFFIX_LENGTH 16
#define MODEM_HANGUPCMD_LENGTH 16
#define MODEM_AUTOANSWERON_LENGTH 16
#define MODEM_AUTOANSWEROFF_LENGTH 16
#define MODEM_PHONES 4
#define MODEM_PHONENUMBER_LENGTH 24

struct MODEM_RW_PARMS {
   /* reserved space for modems */
   char initCmd[MODEM_INITCMD_LENGTH]; /* initialization string */
   char dialingPrefix[MODEM_DIALPREFIX_LENGTH]; /* dialing prefix */
   char dialingSuffix[MODEM_DIALSUFFIX_LENGTH];
   char hangupCmd[MODEM_HANGUPCMD_LENGTH];
   char autoAnswerOnCmd[MODEM_AUTOANSWERON_LENGTH];
   char autoAnswerOffCmd[MODEM_AUTOANSWEROFF_LENGTH];
   char phoneNumber[MODEM_PHONES][MODEM_PHONENUMBER_LENGTH]; /* 4 phone numbers */

   quint8 waitForConnection; /* secs */
   quint8 pauseBetweenCalls; /* secs, 5/21/96 define '0' */
   quint8 maxDialAttempts;

  /*  added 5/21/96 */
   char cellShare;  /* K2 only, =0 for 1 Hz output, =1 for cell phone */
                    /* @ MERGE 9/18/96 -- NOT USED */
   char cellOnTime;       /* in minutes */
   quint8 cellWarmupTime;  /* in seconds */
   int cellStartTime[5];  /* minutes since midnight, 2->5, 6/10/96 */
   char bytepad[4];       /* 10->4, 6/10/96 */

   quint16 flags; /* BIT0 = 1 to enable auto call out
                            BIT1 = 1 to call out on battery < 12 V
                            BIT2 = 1 to call out on battery charge failed
                            BIT3 = 1 to call out on extreme temperature
                            BIT4 = 1 to call out on event
                            BIT5 = 1 to call out on GPS lock failure
                         */
  char calloutMsg[46];   /*  added 5/21/96 */
};

/*---------------------------------------------------*/

/* Group read/write parms into one structure */

struct RW_K2_PARMS {
   struct MISC_RW_PARMS misc;
   struct TIMING_RW_PARMS timing;
   struct CHANNEL_RW_PARMS channel[MAX_K2_CHANNELS];
   struct STREAM_K2_RW_PARMS stream;
   struct MODEM_RW_PARMS modem;
};


/*---------------------------------------------------*/

/* Group read/write parms into one structure */
struct RW_MW_PARMS {
   struct MISC_RW_PARMS misc;
   struct TIMING_RW_PARMS timing;
   struct CHANNEL_RW_PARMS channel[MAX_MW_CHANNELS];
   struct STREAM_MW_RW_PARMS stream;
   struct MODEM_RW_PARMS modem;
};


/*---------------------------------------------------*/

#define FILE_DESCRIPTOR_SIZE 8 /* size of file descriptor */

/*   K2 */
/* Group read only parms into one structure */
struct RO_K2_PARMS {
   /* first 8 bytes is a common file descriptor */
   char id[3]; /* = 'KMI' to denote a Kinemetrics file */
   quint8 instrumentCode; /* = '9' for K2 */
   quint16 headerVersion; /* header version * 100 */
   quint16 headerBytes; /* size of header following (includes RW_PARMS) */

   /* actual header follows */
   struct MISC_RO_PARMS misc;
   struct TIMING_RO_PARMS timing;
   struct CHANNEL_RO_PARMS channel[MAX_K2_CHANNELS];
   struct STREAM_RO_PARMS stream;
};


/*---------------------------------------------------*/

/* Group read only parms into one structure */
struct RO_MW_PARMS {
   /* first 8 bytes is a common file descriptor */
   char id[3]; /* = 'KMI' to denote a Kinemetrics file */
   quint8 instrumentCode; /* = '9' for K2 */
   quint16 headerVersion; /* header version * 100 */
   quint16 headerBytes; /* size of header following (includes RW_PARMS) */

   /* actual header follows */
   struct MISC_RO_PARMS misc;
   struct TIMING_RO_PARMS timing;
   struct CHANNEL_RO_PARMS channel[MAX_MW_CHANNELS];
   struct STREAM_RO_PARMS stream;
};


/* This is what the K2 header looks like */
typedef struct {
   struct RO_K2_PARMS roParms;
   struct RW_K2_PARMS rwParms;
} K2_HEADER;

/* This is what the MtWhitney header looks like */
typedef struct {
   struct RO_MW_PARMS roParms;
   struct RW_MW_PARMS rwParms;
} MW_HEADER;

/*---------------------------------------------------*/
/*---------------------------------------------------*/


/*---------------------------------------------------*/
/* K2 Event Frame Structure */
/*---------------------------------------------------*/

#define FRAME_HEADER_SIZE 32 /* bytes */
#define MW_FRAME_HEADER_TYPE 4  /* 4 for 24 ch */
#define K2_FRAME_HEADER_TYPE 3  /* 3 for 16 ch */
#define TIMECODE_BYTES 13

typedef struct { /* 32 bytes */
   quint8 frameType; /* like a version #, = FRAME_HEADER_TYPE */
   quint8 instrumentCode; /* instrument code */
   quint16 recorderID;
   quint16 frameSize; /* # of frame bytes, includes 32 byte header */
   quint32 blockTime; /* block time */
   quint16 channelBitMap; /* 1 bit for each ch. in use. Ch. 1 is bit 0 */
   quint16 streamPar; /* see comments below */
   quint8 frameStatus; /* see comments below */
   quint8 frameStatus2; /* see comments below */
   quint16 msec; /* 0..999 */
        quint8 channelBitMap1; /* extended chan bit map, ch17-24 */
   quint8 timeCode[TIMECODE_BYTES]; /* time code, see comment below */
} FRAME_HEADER;

/* FRAME_HEADER Description:
   frameStatus:
          Bits 0-3 = frame sequence number 0..9
          Bit 4    = stream triggered flag. Set if frame exceeds stream trigger level.
          Bit 5    = Compressed flag. Set if compressed frame.
          Bits 6-7 = Sample size. 1=16 bits (2 bytes), 2=24 bits (3 bytes)
                                                          3=32 bits (4 bytes)
                                 Samples are expressed as a signed integer of digital counts.
   frameStatus2:
          Bit 0 = set if issued the ADD SCAN command
          Bits 1-7: currently unused.

   streamPar:
          Bits 0-11 = Stream sampling rate, 1..4095
          Bits 12-15 = Stream number 0..15

   timeCode[]:
          Time code sampled every millisecond.
          Bits 4-7 of timeCode[0] = time code type (TBD)
          Bit 3 of timeCode[0] = time code bit sampled at first msec of frame (0=low, 1=high)
          Bit 2 of timeCode[0] = time code bit at 2nd msec.
          Bit 0 of timeCode[12] = last (100th msec) bit of time code
*/

/*----------------------------------------------------*/
/*----------------------------------------------------*/


/*----------------------------------------------------*/
/*    K2 TAG FRAME HEADER */
/*----------------------------------------------------*/
/* STRUCTURE TYPE CODES */
#define KFF_K2_HDR 1 /* K2 header */
#define KFF_K2_FRAME 2 /* K2 FRAME; frame data follows */
#define KFF_BYTE_ORDER 1/* 0=INTEL (LSB first) , 1 = MOTOROLA (MSB first) */
#define KFF_VERSION 1
#define KFF_SYNC_CHAR 'K'


/* TAG. Separates and identifies structures */
typedef struct {
   quint8 sync; /* sync character 'K' */
   quint8 byteOrder; /* = 0 for LSB first (INTEL), 1 for MSB first (MOTOROLA) */
   quint8 version; /* File format version; KFF_VERSION */
   quint8 instrumentType; /* instrument type code */
   quint32 type; /* structure type code */
   quint16 length; /* structure size in bytes */
   quint16 dataLength; /* # of data bytes following the structure */
   quint16 id; /* unique instrument id (e.g. serial number); used for multi-instrument files */
   quint16 checksum; /* 16 bit checksum of structure + data */
} KFF_TAG;

/*---------------------------------------------------*/
/*---------------------------------------------------*/


