/*
 * stack.c
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





/*
 *----------------------------------------------------------------------
 *   Include Files
 *----------------------------------------------------------------------
 */
#include "stack.h"

/*
 *----------------------------------------------------------------------
 *   Private Defines
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Private Macros
 *----------------------------------------------------------------------
 */


/*
 *----------------------------------------------------------------------
 *   Private Data Types
 *----------------------------------------------------------------------
 */


/*
 *----------------------------------------------------------------------
 *   Public Variables
 *----------------------------------------------------------------------
 */


/*
 *----------------------------------------------------------------------
 *   Private Variables (static)
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Public Constants
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Private Constants (static)
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Private Function Prototypes (static)
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Private Functions Definitions
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *   Export Functions Definitions
 *----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *  Function: Stack_RetCode_t Initialize(PStack_t pStack)
 *
 *  Summary	: This function initializes the Stack data structure
 *
 *  Input	: pStack - Pointer to Stack
 *
 *  Output	: Result of Stack Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Stack_RetCode_t Initialize(PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;
	size_t dataSize = 0;

	if (pStack)
	{
		pStack->Current = 0;
		result = Stk_OK;
		switch(pStack->Datatype)
		{
		case DT_BOOL:
			dataSize = pStack->MaxNumberOfElements*sizeof(BOOL);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: Boolean datatype Stack\n");
#endif
			break;
		case DT_UINT8:
			dataSize = pStack->MaxNumberOfElements*sizeof(UINT8);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: UINT8 datatype Stack\n");
#endif
			break;
		case DT_INT8:
			dataSize = pStack->MaxNumberOfElements*sizeof(INT8);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: INT8 datatype Stack\n");
#endif
			break;
		case DT_UINT16:
			dataSize = pStack->MaxNumberOfElements*sizeof(UINT16);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: UINT16 datatype Stack\n");
#endif
			break;
		case DT_INT16:
			dataSize = pStack->MaxNumberOfElements*sizeof(INT16);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: INT16 datatype Stack\n");
#endif
			break;
		case DT_UINT32:
			dataSize = pStack->MaxNumberOfElements*sizeof(UINT32);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: UINT32 datatype Stack\n");
#endif
			break;
		case DT_INT32:
			dataSize = pStack->MaxNumberOfElements*sizeof(INT32);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: INT32 datatype Stack\n");
#endif
			break;
		case DT_FLOAT:
			dataSize = pStack->MaxNumberOfElements*sizeof(FLOAT32);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: Float datatype Stack\n");
#endif
			break;
		case DT_DOUBLE:
			dataSize = pStack->MaxNumberOfElements*sizeof(FLOAT64);
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: Double datatype Stack\n");
#endif
			break;
		default:
			dataSize = 0;
			result = Stk_INVALIDDATATYPE;
#ifdef DEBUG_STACK
			printf("\nSTACK_ERR: Invalid Datatype\n");
#endif
			break;
		}

		if (result == Stk_OK)
		{
#ifdef __USE_DYNAMIC_MEMORY
			if ( (pStack->Ptr = (PStack_t)malloc(dataSize)) == NULL)
			{
				printf("\nSTACK_ERR: Allocation Failure\n");
				result = Stk_INVALIDALLOCATION;
			}
			else
			{
#endif
			memset(pStack->Ptr, 0, dataSize);
#ifdef __USE_DYNAMIC_MEMORY
			}
#endif
		}
	}
#ifdef DEBUG_STACK
	else
	{
		printf("\nSTACK_ERR: NULL Stack\n");
	}
#endif
	return result;
}


 /*
  *----------------------------------------------------------------------
  *  Function: Stack_RetCode_t Push(void *itemToPush, PStack_t pStack)
  *
  *  Summary : This function Pushes an Element on to Stack Top
  *
  *  Input	 : pStack - Pointer to Stack, itemToPush - pointer to Element to Push
  *
  *  Output	 : Result of Stack Operation as Enum
  *
  *  Notes	 :
  *
  *----------------------------------------------------------------------
  */
Stack_RetCode_t Push(void *itemToPush, PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;
	if (pStack)
	{
		result = Stk_OK;
		if (pStack->Current >= pStack->MaxNumberOfElements)
		{
			result = Stk_FULL;
#ifdef DEBUG_STACK
			printf("\nSTACK_ERR: Stack Full\n");
#endif
		}
		else
		{
			if (itemToPush)
			{
				switch(pStack->Datatype)
				{
				case DT_BOOL:
					((BOOL *)pStack->Ptr)[pStack->Current++] = (BOOL)*((BOOL *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> %d\n", (BOOL)*((BOOL *)itemToPush));
#endif
					break;
				case DT_UINT8:
					((UINT8 *)pStack->Ptr)[pStack->Current++] = (UINT8)*((UINT8 *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> 0x%02x\n", (UINT8)*((UINT8 *)itemToPush));
#endif
					break;
				case DT_INT8:
					((INT8 *)pStack->Ptr)[pStack->Current++] = (INT8)*((INT8 *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> %d\n", (INT8)*((INT8 *)itemToPush));
#endif
					break;
				case DT_UINT16:
					((UINT16 *)pStack->Ptr)[pStack->Current++] = (UINT16)*((UINT16 *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> 0x%04x\n", (UINT16)*((UINT16 *)itemToPush));
#endif
					break;
				case DT_INT16:
					((INT16 *)pStack->Ptr)[pStack->Current++] = (INT16)*((INT16 *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> %d\n", (INT16)*((INT16 *)itemToPush));
#endif
					break;
				case DT_UINT32:
					((UINT32 *)pStack->Ptr)[pStack->Current++] = (UINT32)*((UINT32 *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> 0x%08x\n", (UINT32)*((UINT32 *)itemToPush));
#endif
					break;
				case DT_INT32:
					((INT32 *)pStack->Ptr)[pStack->Current++] = (INT32)*((INT32 *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> %d\n", (INT32)*((INT32 *)itemToPush));
#endif
					break;
				case DT_FLOAT:
					((FLOAT32 *)pStack->Ptr)[pStack->Current++] = (FLOAT32)*((FLOAT32 *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> %f\n", (FLOAT32)*((FLOAT32 *)itemToPush));
#endif
					break;
				case DT_DOUBLE:
					((FLOAT64 *)pStack->Ptr)[pStack->Current++] = (FLOAT64)*((FLOAT64 *)itemToPush);
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Push -> %f\n", (FLOAT64)*((FLOAT64 *)itemToPush));
#endif
					break;
				default:
					result = Stk_INVALIDDATATYPE;
#ifdef DEBUG_STACK
					printf("\nSTACK_ERR: Invalid Datatype\n");
#endif
					break;
				}
			}
			else
			{
				result = Stk_INVALIDELEMENT;
#ifdef DEBUG_STACK
				printf("\nSTACK_ERR: Invalid Element Container\n");
#endif
			}
		}
	}
#ifdef DEBUG_STACK
	else
	{
		printf("\nSTACK_ERR: NULL Stack\n");
	}
#endif
	return result;
}


/*
 *----------------------------------------------------------------------
 *  Function: Stack_RetCode_t Pop(void *poppedItem, PStack_t pStack)
 *
 *  Summary : This function Pops an Element from Stack Top
 *
 *  Input	: pStack - Pointer to Stack, poppedItem - pointer to Element
 *            to Pop into
 *
 *  Output	: Result of Stack Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Stack_RetCode_t Pop(void *poppedItem, PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;
	if (pStack)
	{
		result = Stk_OK;
		if (pStack->Current == 0)
		{
			result = Stk_EMPTY;
#ifdef DEBUG_STACK
			printf("\nSTACK_ERR: Stack Empty\n");
#endif
		}
		else
		{
			if (poppedItem)
			{
				switch(pStack->Datatype)
				{
				case DT_BOOL:
					*((BOOL *)poppedItem) = (BOOL)((BOOL *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> %d\n", *((BOOL *)poppedItem));
#endif
					break;
				case DT_UINT8:
					*((UINT8 *)poppedItem) = (UINT8)((UINT8 *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> 0x%02x\n", *((UINT8 *)poppedItem));
#endif
					break;
				case DT_INT8:
					*((INT8 *)poppedItem) = (INT8)((INT8 *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> %d\n", *((INT8 *)poppedItem));
#endif
					break;
				case DT_UINT16:
					*((UINT16 *)poppedItem) = (UINT16)((UINT16 *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> 0x%04x\n", *((UINT16 *)poppedItem));
#endif
					break;
				case DT_INT16:
					*((INT16 *)poppedItem) = (INT16)((INT16 *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> %d\n", *((INT16 *)poppedItem));
#endif
					break;
				case DT_UINT32:
					*((UINT32 *)poppedItem) = (UINT32)((UINT32 *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> 0x%08x\n", *((UINT32 *)poppedItem));
#endif
					break;
				case DT_INT32:
					*((INT32 *)poppedItem) = (INT32)((INT32 *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> %d\n", *((INT32 *)poppedItem));
#endif
					break;
				case DT_FLOAT:
					*((FLOAT32 *)poppedItem) = (FLOAT32)((FLOAT32 *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> %f\n", *((FLOAT32 *)poppedItem));
#endif
					break;
				case DT_DOUBLE:
					*((FLOAT64 *)poppedItem) = (FLOAT64)((FLOAT64 *)pStack->Ptr)[--pStack->Current];
#ifdef DEBUG_STACK
					printf("\nSTACK_INFO: Pop -> %f\n", *((FLOAT64 *)poppedItem));
#endif
					break;
				default:
					result = Stk_INVALIDDATATYPE;
#ifdef DEBUG_STACK
					printf("\nSTACK_ERR: Invalid Datatype\n");
#endif
					break;
				}
			}
			else
			{
				result = Stk_INVALIDELEMENT;
#ifdef DEBUG_STACK
					printf("\nSTACK_ERR: Invalid Element Container\n");
#endif
			}
		}
	}
#ifdef DEBUG_STACK
	else
	{
		printf("\nSTACK_ERR: NULL Stack\n");
	}
#endif
	return result;
}


/*
 *----------------------------------------------------------------------
 *  Function: Stack_RetCode_t Full(PStack_t pStack
 *
 *  Summary : This function Checks for Stack Full
 *
 *  Input	: pStack - Pointer to Stack
 *
 *  Output	: Result of Stack Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Stack_RetCode_t Full(PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;
	if (pStack)
	{
		result = Stk_OK;
		if (pStack->Current >= pStack->MaxNumberOfElements)
		{
			result = Stk_FULL;
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: Stack Full\n");
#endif
		}
#ifdef DEBUG_STACK
		else
		{
			printf("\nSTACK_INFO: Stack not full\n");
		}
#endif

	}
#ifdef DEBUG_STACK
	else
	{
		printf("\nSTACK_ERR: NULL Stack\n");
	}
#endif
	return result;
}


/*
 *----------------------------------------------------------------------
 *  Function: Stack_RetCode_t Empty(PStack_t pStack
 *
 *  Summary : This function Checks for Stack Empty
 *
 *  Input	: pStack - Pointer to Stack
 *
 *  Output	: Result of Stack Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Stack_RetCode_t Empty(PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;
	if (pStack)
	{
		result = Stk_OK;
		if (pStack->Current == 0)
		{
			result = Stk_EMPTY;
#ifdef DEBUG_STACK
			printf("\nSTACK_INFO: Stack Empty\n");
#endif
		}
#ifdef DEBUG_STACK
		else
		{
			printf("\nSTACK_INFO: Stack not empty\n");
		}
#endif
	}
#ifdef DEBUG_STACK
	else
	{
		printf("\nSTACK_ERR: NULL Stack\n");
	}
#endif
	return result;
}



/*
 *----------------------------------------------------------------------
 *  Function: Stack_RetCode_t DeInitialize(PStack_t pStack)
 *
 *  Summary	: This function un-initializes the Stack data structure
 *
 *  Input	: pStack - Pointer to Stack
 *
 *  Output	: Result of Stack Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Stack_RetCode_t DeInitialize(PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;

	if (pStack)
	{
		result = Stk_OK;
#ifdef __USE_DYNAMIC_MEMORY
		free(pStack->Ptr);
#ifdef DEBUG_STACK
		printf("\nSTACK_INFO: Memory is Free'd\n");
#endif
#endif
	}
#ifdef DEBUG_STACK
	else
	{
		printf("\nSTACK_ERR: NULL Stack\n");
	}
#endif
	return result;
}
