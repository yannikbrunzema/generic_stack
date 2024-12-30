#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct
{
    void **data;       // Array of void pointers
    size_t size;       // Current size of the stack
    size_t capacity;   // Maximum capacity of the stack
} Stack;

Stack *createStack(size_t capacity);
void push(Stack *stack, void *data);
void* pop(Stack *stack, void **data);
bool isStackEmpty(const Stack *stack);
bool isStackFull(const Stack *stack);
void destroyStack(Stack **stack);


#endif //STACK_H
