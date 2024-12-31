#include <stdio.h>
#include "../stack.h"

void assert_true(int condition, const char *test_name)
{
    if (condition)
    {
        printf("PASS: %s\n", test_name);
    }
    else
    {
        printf("FAIL: %s\n", test_name);
    }
}

int main()
{
    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    Stack *stack = createStack(10);

    push(stack, &val1);
    assert_true(stack->data[0] == &val1, "push_val");

    push(stack, &val2);
    push(stack, &val3);
    assert_true(stack->size == 3, "stack_size");

    int result = *(int*)(pop(stack));
    assert_true(result == 3, "pop_val");
    assert_true(stack->size == 2, "stack_size");

    fflush(stdout);
    destroyStack(&stack);
    return 0;
}