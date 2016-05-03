/*
 * stack.c
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
Stack_RetCode_t Initialize(PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;
	if (pStack)
	{
		pStack->Current = 0;
		result = Stk_OK;
		switch(pStack->Datatype)
		{
		case DT_BOOL:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(BOOL));
			break;
		case DT_UINT8:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(UINT8));
			break;
		case DT_INT8:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(INT8));
			break;
		case DT_UINT16:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(UINT16));
			break;
		case DT_INT16:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(INT16));
			break;
		case DT_UINT32:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(UINT32));
			break;
		case DT_INT32:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(INT32));
			break;
		case DT_FLOAT:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(FLOAT32));
			break;
		case DT_DOUBLE:
			memset(pStack->Ptr, 0, pStack->Size*sizeof(FLOAT64));
			break;
		default:
			result = Stk_INVALIDDATATYPE;
#ifdef DEBUG_STACK
			printf("\nSTACK_ERR: Invalid Datatype\n");
#endif
			break;
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



Stack_RetCode_t Push(void *itemToPush, PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;
	if (pStack)
	{
		result = Stk_OK;
		if (pStack->Current >= pStack->Size)
		{
			result = Stk_FULL;
#ifdef DEBUG_STACK
			printf("\nSTACK_ERR: Stack Full\n");
#endif
		}
		else
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
	}
#ifdef DEBUG_STACK
	else
	{
		printf("\nSTACK_ERR: NULL Stack\n");
	}
#endif
	return result;
}



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
	}
#ifdef DEBUG_STACK
	else
	{
		printf("\nSTACK_ERR: NULL Stack\n");
	}
#endif
	return result;
}



Stack_RetCode_t Full(PStack_t pStack)
{
	Stack_RetCode_t result = Stk_INVALIDSTACK;
	if (pStack)
	{
		result = Stk_OK;
		if (pStack->Current >= pStack->Size)
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
