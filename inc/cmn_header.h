/*
 * cmn_header.h
 *
 *  Created on: 02-May-2016
 *      Author: MSamal
 *
 *  LICENSE:-
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INC_CMN_HEADER_H_
#define INC_CMN_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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


typedef enum _ENDIAN
{
	__ENDIAN_LITTLE = 0,
	__ENDIAN_BIG,
	__ENDIAN_MAX
}_ENDIAN;

typedef enum DataType_t
{
	DT_BOOL = 0,
	DT_CHAR,
	DT_UINT8,
	DT_INT8,
	DT_UINT16,
	DT_INT16,
	DT_UINT32,
	DT_INT32,
	DT_FLOAT,
	DT_DOUBLE,
	DT_MAX
}DataType_t;




#endif /* INC_CMN_HEADER_H_ */
