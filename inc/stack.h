/*
 * stack.h
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

#ifndef INC_STACK_H_
#define INC_STACK_H_

#include "cmn_header.h"


#define DEBUG_STACK


struct Stack_t
{
	DataType_t Datatype;
	void *Ptr;
	size_t Size;
	size_t Current;
}__ATTRIBUTE__(packed);
typedef struct Stack_t Stack_t;
typedef struct Stack_t * PStack_t;


typedef enum Stack_RetCode_t
{
	Stk_OK	= 0,
	Stk_INVALIDSTACK,
	Stk_INVALIDDATATYPE,
	Stk_EMPTY,
	Stk_FULL,
	Stk_MAX
}Stack_RetCode_t;


Stack_RetCode_t Initialize(PStack_t pStack);
Stack_RetCode_t Push(void *itemToPush, PStack_t pStack);
Stack_RetCode_t Pop(void *poppedItem, PStack_t pStack);
Stack_RetCode_t Full(PStack_t pStack);
Stack_RetCode_t Empty(PStack_t pStack);

#endif /* INC_STACK_H_ */
