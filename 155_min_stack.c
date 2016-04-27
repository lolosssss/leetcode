/**
 * Description : Min Stack
 *               Design a stack that supports push, pop, top, and retrieving the
 *               minimum element in constant time.
 *               * push(x)  -- Push element x onto stack
 *               * pop()    -- Removes the element on top of the stack
 *               * top()    -- Get the top element
 *               * getMin() -- Retrieve the minimum element in the stack
 * Author      : Evan Lau
 * Date        : 2016/04/13
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int *min;
    int dataTop;
    int minTop;
    int size;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize)
{
    stack->data = (int *)malloc(sizeof(int) * maxSize);
    stack->min = (int *)malloc(sizeof(int) * maxSize);
    stack->dataTop = -1;
    stack->minTop = -1;
    stack->size = maxSize;
}

void minStackPush(MinStack *stack, int element)
{
    stack->dataTop++;
    if (stack->dataTop >= stack->size)
    {
        stack->dataTop--;
        return;
    }
    stack->data[stack->dataTop] = element;
    if (stack->minTop < 0 || stack->min[stack->minTop] >= element)
    {
        stack->min[++stack->minTop] = element;
    }
}

void minStackPop(MinStack *stack)
{
    if (stack->min[stack->minTop] == stack->data[stack->dataTop])
    {
        stack->minTop--;
    }
    stack->data[stack->dataTop--] = 0;
}

int minStackTop(MinStack *stack)
{
    return stack->data[stack->dataTop];
}

int minStackGetMin(MinStack *stack)
{
    return stack->min[stack->minTop];
}

void minStackDestroy(MinStack *stack)
{
    free(stack->data);
    stack->data = NULL;
    free(stack->min);
    stack->min = NULL;
}

int main(void)
{
    MinStack s;
    MinStack *stack = &s;

    minStackCreate(stack, 100);

    minStackPush(stack, 85);
    minStackPush(stack, -99);
    minStackPush(stack, 67);
    printf("%d\n", minStackGetMin(stack));

    minStackDestroy(stack);

    return 0;
}
