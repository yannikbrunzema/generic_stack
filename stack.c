#include <stdlib.h>
#include <stddef.h>
#include "stack.h"

Stack* createStack(const size_t capacity)
{
    // Allocate the stack struct on the heap
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    if (stack == NULL)
        return NULL;

    // Allocate stacks data
    stack->data = (void **)malloc(capacity * sizeof(void *));
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}


bool isStackEmpty(const Stack *stack)
{
    return stack->size == 0;
}

bool isStackFull(const Stack *stack)
{
    return stack->size == stack->capacity;
}

void push(Stack *stack, void *data)
{
    if (stack->size == stack->capacity)
        return;
    stack->data[stack->size] = data;
    stack->size++;
}

void* pop(Stack *stack)
{
    if (stack->size == 0)
        return NULL;
    return stack->data[--stack->size];
}

void destroyStack(Stack **stack)
{
    if (*stack != NULL)
    {
        free((*stack)->data);
        free(*stack);
        *stack = NULL;
    }
}