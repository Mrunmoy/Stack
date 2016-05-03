/*
 * cmn_header.h
 *
 *  Created on: 02-May-2016
 *      Author: MSamal
 *
 *  LICENSE:-
 *  The MIT License (MIT)
 *  Copyright (c) 2016 Mrunmoy Samal
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom
 *  the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall
 *  be included in all copies or substantial portions of the
 *  Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 *  OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef INC_CMN_HEADER_H_
#define INC_CMN_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//! DEBUG_STACK.
/*!
		      Comment first line and uncomment
		      second one to see enable struct
		      packing.
 */
#define __ATTRIBUTE__(x)
//#define __ATTRIBUTE__(x)    __attribute__(x)


typedef unsigned long long 	UINT64;
typedef long long 			INT64;

typedef unsigned int 		UINT32;
typedef int 				INT32;

typedef double 				FLOAT64;
typedef float               FLOAT32;

typedef unsigned short 		UINT16;
typedef short 				INT16;

typedef unsigned char 		UINT8;
typedef char 				INT8;

typedef char 				CHAR;

typedef char 				BOOL;


#define _STATIC				static
#define _CONST				const
#define _EXTERN				extern
#define _VOID				void
#define FALSE				0
#define TRUE				1

#define BE_BIG_END				0
#define BE_LITTLE_END			1

#define LE_BIG_END				1
#define LE_LITTLE_END			0

#define CRC_HIGH_BYTE			0
#define CRC_LOW_BYTE			1

//! _ENDIAN enum.
/*! Endian Definition. */
typedef enum _ENDIAN
{
	__ENDIAN_LITTLE = 0,
	__ENDIAN_BIG,
	__ENDIAN_MAX
}_ENDIAN;


//! DataType_t enum.
/*! data type Definition. */
typedef enum DataType_t
{
	DT_BOOL = 0,	/**< enum value DT_BOOL = 0. Indicates Boolean data type. */
	DT_CHAR,		/**< enum value DT_CHAR = 1. Indicates char data type. */
	DT_UINT8,		/**< enum value DT_UINT8 = 2. Indicates unsigned int 8-bit data type. */
	DT_INT8,		/**< enum value DT_INT8 = 3. Indicates signed int 8-bit data type. */
	DT_UINT16,		/**< enum value DT_UINT16 = 4. Indicates unsigned int 16-bit data type. */
	DT_INT16,		/**< enum value DT_INT16 = 5. Indicates signed int 16-bit data type. */
	DT_UINT32,		/**< enum value DT_UINT32 = 6. Indicates unsigned int 32-bit data type. */
	DT_INT32,		/**< enum value DT_INT32 = 7. Indicates signed int 32-bit data type. */
	DT_FLOAT,		/**< enum value DT_FLOAT = 8. Indicates float data type. */
	DT_DOUBLE,		/**< enum value DT_DOUBLE = 9. Indicates double data type. */
	DT_MAX			/**< enum value DT_MAX = 10. Max Count. */
}DataType_t;




#endif /* INC_CMN_HEADER_H_ */
