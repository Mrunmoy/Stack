/*
 * test.c
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
#define STACK_SIZE		(5)

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
int main(int argc, char * argv[])
{
	Stack_t myStack;
	INT32 myStackData[STACK_SIZE];
	INT32 var;

	myStack.Datatype 	= DT_INT32;
	myStack.Size 		= STACK_SIZE;
	myStack.Ptr 		= myStackData;

	printf("\n--- Initialize Test ---\n");
	if ( Stk_OK == Initialize(&myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- Empty Test ---\n");
	if ( Stk_EMPTY == Empty(&myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- Push Test ---\n");
	var = 5;
	printf("\nPushing %d\n", var);
	if ( Stk_OK == Push(&var, &myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 10;
	printf("\nPushing %d\n", var);
	if ( Stk_OK == Push(&var, &myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 15;
	printf("\nPushing %d\n", var);
	if ( Stk_OK == Push(&var, &myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 20;
	printf("\nPushing %d\n", var);
	if ( Stk_OK == Push(&var, &myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 25;
	printf("\nPushing %d\n", var);
	if ( Stk_OK == Push(&var, &myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 30;
	printf("\nPushing %d\n", var);
	if ( Stk_OK == Push(&var, &myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- Full Test ---\n");
	if ( Stk_FULL == Full(&myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- Pop Test ---\n");
	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("\nPopped %d\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("\nPopped %d\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("\nPopped %d\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("\nPopped %d\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("\nPopped %d\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("\nPopped %d\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- Empty Test ---\n");
	if ( Stk_EMPTY == Empty(&myStack))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	return 0;
}


/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/
