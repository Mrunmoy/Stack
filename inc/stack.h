/*
 * stack.h
 *
 *  Created on: 02-May-2016
 *      Author: Mrunmoy Samal
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

#ifndef INC_STACK_H_
#define INC_STACK_H_

#include "cmn_header.h"

//! DEBUG_STACK.
/*!
		      uncomment to see stack debug msgs.
 */
//#define DEBUG_STACK


//! __USE_DYNAMIC_MEMORY.
/*!
		      uncomment to use dynamic memory allocation.
 */
//#define __USE_DYNAMIC_MEMORY


/*! \struct Stack_t
    \brief  Stack Data Structure Definition.

   Stack Data Structure Definition
   used for all stack operations.
*/
struct Stack_t
{
	//! Datatype.
	/*!
		      The Data Type used in the stack.
	 */
	DataType_t Datatype;
	//! Ptr.
	/*!
		      Pointer to the Stack Data.
	 */
	void *Ptr;
	//! MaxNumberOfElements.
	/*!
		      total number of elements in the stack.
	 */
	size_t MaxNumberOfElements;
	//! Current.
	/*!
		      stack element count and current position.
	 */
	size_t Current;
}__ATTRIBUTE__(packed);
typedef struct Stack_t Stack_t;
typedef struct Stack_t * PStack_t;

//! Stack_RetCode_t enum.
/*! Stack Operation Return Code Definition. */
typedef enum Stack_RetCode_t
{
	Stk_OK	= 0,			/**< enum value Stk_OK = 0. Indicates stack operation was successful. */
	Stk_INVALIDSTACK,		/**< enum value Stk_INVALIDSTACK = 1. Indicates a NULL Stack Pointer. */
	Stk_INVALIDDATATYPE,	/**< enum value Stk_INVALIDDATATYPE = 2. Indicates invalid stack data type. */
	Stk_INVALIDELEMENT,		/**< enum value Stk_INVALIDELEMENT = 3. Indicates invalid element container. */
#ifdef __USE_DYNAMIC_MEMORY
	Stk_INVALIDALLOCATION,	/**< enum value Stk_INVALIDALLOCATION = 4. Indicates invalid memory allocation. */
#endif
	Stk_EMPTY,				/**< enum value Stk_EMPTY = 4. Indicates stack is empty. */
	Stk_FULL,				/**< enum value Stk_FULL = 5. Indicates stack is full. */
	Stk_MAX					/**< enum value Stk_MAX = 6. Max counter. */
}Stack_RetCode_t;




/*! \fn Stack_RetCode_t Initialize(PStack_t pStack)

    \brief This function initializes the Stack for all further operations.

    \param pStack is of type PStack_t. It is the Stack Data Structure pointer.
*/
Stack_RetCode_t Initialize(PStack_t pStack);


/*! \fn Stack_RetCode_t Push(void *itemToPush, PStack_t pStack)

    \brief This function pushes an element on to the Stack top.

    \param itemToPush is of type void. It is pointer to the actual data to be pushed.
    \param pStack is of type PStack_t. It is the Stack Data Structure pointer.
*/
Stack_RetCode_t Push(void *itemToPush, PStack_t pStack);


/*! \fn Stack_RetCode_t Pop(void *poppedItem, PStack_t pStack)

    \brief This function pops an element from the Stack top.

    \param poppedItem is of type void. It is pointer to the data container to store the popped item.
    \param pStack is of type PStack_t. It is the Stack Data Structure pointer.
*/
Stack_RetCode_t Pop(void *poppedItem, PStack_t pStack);


/*! \fn Stack_RetCode_t Full(PStack_t pStack)

    \brief This function checks if the Stack is Full.

    \param pStack is of type PStack_t. It is the Stack Data Structure pointer.
*/
Stack_RetCode_t Full(PStack_t pStack);


/*! \fn Stack_RetCode_t Empty(PStack_t pStack)

    \brief This function checks for Empty Stack.

    \param pStack is of type PStack_t. It is the Stack Data Structure pointer.
*/
Stack_RetCode_t Empty(PStack_t pStack);


/*! \fn Stack_RetCode_t DeInitialize(PStack_t pStack)

    \brief This function un-initializes the Stack for all further operations.

    \param pStack is of type PStack_t. It is the Stack Data Structure pointer.
*/
Stack_RetCode_t DeInitialize(PStack_t pStack);


#endif /* INC_STACK_H_ */
