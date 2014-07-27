/*
 *   THIS FILE IS UNDER RCS - DO NOT MODIFY UNLESS YOU HAVE
 *   CHECKED IT OUT USING THE COMMAND CHECKOUT.
 *
 *    $Id: byteswap.h 2118 2006-04-03 16:01:04Z stefan $
 *
 *    Revision history:
 *     $Log$
 *     Revision 1.2  2006/04/03 16:01:04  stefan
 *     *** empty log message ***
 *
 *     Revision 1.1  2000/05/04 23:47:27  lombard
 *     Initial revision
 *
 *
 *
 *
 */
/*   byteswap.h:  Defines byte-swap macros to convert between "Intel" and */
/*                "Motorola" byte ordered integers */

/*     1/6/99 -- [ET]  File started */

#define K2_TIME_CONV ((unsigned long)315532800)

#ifdef _INTEL
/*  macro returns byte-swapped version of given 16-bit unsigned integer */
#define BYTESWAP_UINT16(var) \
               ((unsigned short)(((unsigned short)(var)>>(unsigned char)8) + \
               ((unsigned short)(var)<<(unsigned char)8)))

/*  macro returns byte-swapped version of given 32-bit unsigned integer */
#define BYTESWAP_UINT32(var) \
                 ((unsigned long)(((unsigned long)(var)>>(unsigned char)24) + \
        (((unsigned long)(var)>>(unsigned char)8)&(unsigned long)0x0000FF00)+ \
        (((unsigned long)(var)<<(unsigned char)8)&(unsigned long)0x00FF0000)+ \
                                 ((unsigned long)(var)<<(unsigned char)24)))


#endif
#ifdef _SPARC
#define BYTESWAP_UINT16(var) (var)
#define BYTESWAP_UINT32(var) (var)
#endif
