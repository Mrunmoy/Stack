#include <stdlib.h>
#include "stack.h"

Stack_t* stack_create(int size)
{
	Stack_t* stack = malloc(sizeof(Stack_t));
	stack->data = malloc(size * sizeof(void *));
	stack->size = size;
	stack->top = -1;
	return stack;
}

int stack_push(Stack_t* stack, void* data)
{
	if (stack_is_full(stack))
	{
		// Stack_t is full, cannot push more data
		return 0;
	}
	stack->top++;
	stack->data[stack->top] = data;
	return 1;
}

void* stack_pop(Stack_t* stack)
{
	if (stack_is_empty(stack))
	{
		// Stack_t is empty, cannot pop data
		return NULL;
	}

	void *data = stack->data[stack->top];
	stack->top--;
	return data;
}

int stack_is_empty(Stack_t* stack)
{
	return stack && stack->top == -1;
}

int stack_is_full(Stack_t* stack)
{
    return stack && (stack->top == stack->size - 1);
}

void* stack_peek(Stack_t* stack)
{
    if (stack_is_empty(stack))
        return NULL;

    return stack->data[stack->top];
}

void stack_destroy(Stack_t* stack)
{
	free(stack->data);
	free(stack);
}
