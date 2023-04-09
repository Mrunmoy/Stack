#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Stack_t {
    void **data;
    int size;
    int top;
} Stack_t;

Stack_t *stack_create(int size);
int stack_push(Stack_t *stack, void *data);
void *stack_pop(Stack_t *stack);
int stack_is_empty(Stack_t *stack);
int stack_is_full(Stack_t* stack);
void* stack_peek(Stack_t* stack);
void stack_destroy(Stack_t *stack);

#ifdef __cplusplus
}
#endif


#endif /* STACK_H */
