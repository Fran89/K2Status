#include "k2pktdef.h"

#define	TRACE2_STA_LEN	7
#define	TRACE2_CHAN_LEN	9  /* 4 bytes plus padding for loc and version */
#define	TRACE2_NET_LEN	9
#define TRACE2_LOC_LEN   3

#define K2INFO_TYPE_STRING "TYPE_K2INFO_PACKET"

typedef struct {
        char    net[TRACE2_NET_LEN];     /* Network name */
        char    sta[TRACE2_STA_LEN];     /* Site name */
	short  	data_type;		/* see K2INFO_TYPE #defines below */
	unsigned long	epoch_sent;	/* local time sent */
	short   reserved[5];		/* reserved for future use */
} K2INFO_HEADER;

#define K2INFO_TYPE_HEADER    1		/* k2 header params */
#define K2INFO_TYPE_STATUS    2		/* k2 regular status packet */
#define K2INFO_TYPE_ESTATUS   3		/* k2 extended status packet (old) */
#define K2INFO_TYPE_E2STATUS  4		/* k2 extended status packet v2 */
#define K2INFO_TYPE_COMM      5		/* k2ew packet processing stats */

#define MAX_K2INFOBUF_SIZ 4096

typedef union {
        char    msg[MAX_K2INFOBUF_SIZ];
	K2INFO_HEADER k2info;
} K2infoPacket;  


/* FUNCTIONS: only 2 */
int k2info_init();
void k2info_send(int data_type, char *item);
