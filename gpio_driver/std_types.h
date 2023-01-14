/*
 * @author: Abdelrahman Yasser
 *  @breif: Standard fixed length integer types.
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifndef TRUE
#define TRUE (1u)
#endif

#ifndef FALSE
#define FASLE (0u)
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef unsigned char uint8;
typedef signed char sint8;

typedef unsigned short uint16;
typedef signed short sint16;

typedef unsigned long uint32;
typedef signed long sint32;

#endif