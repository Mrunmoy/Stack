/*
 * test.c
 *
 *  Created on: 02-May-2016
 *      Author: Mrunmoy Samal
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
#ifndef __USE_DYNAMIC_MEMORY
	INT32 myStackData[STACK_SIZE];
#endif
	INT32 var;

	myStack.Datatype 	= DT_INT32;
	myStack.MaxNumberOfElements 		= STACK_SIZE;
#ifndef __USE_DYNAMIC_MEMORY
	myStack.Ptr 		= myStackData;
#endif

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
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Stk_OK == Pop(&var, &myStack))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
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

	printf("\n--- DeInit Test ---\n");
	if ( Stk_OK == DeInitialize(&myStack))
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
