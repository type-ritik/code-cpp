#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack *create_stack();

int is_empty(Stack *);

int is_full(Stack *);

void push(Stack *, int);

int pop(Stack *);

int capacity(Stack *);

void delete_stack(Stack *);

void double_stack(Stack *);

int main(void)
{
    Stack *stack = create_stack();
    push(stack, 5);
    printf("Stack capacity: %d\n", capacity(stack));
    push(stack, 10);
    printf("Stack capacity: %d\n", capacity(stack));
    push(stack, 15);
    push(stack, 20);
    printf("Stack capacity: %d\n", capacity(stack));
    push(stack, 50);
    push(stack, 55);
    printf("Stack capacity: %d\n", capacity(stack));
    printf("Popped element: %d\n", pop(stack));
    return 0;
}

Stack *create_stack()
{
    Stack *stack = malloc(sizeof(Stack));
    if (!stack)
    {
        printf("Error: Creating stack.\n");
        return NULL;
    }

    stack->top = -1;
    stack->capacity = 1;
    stack->array = malloc(stack->capacity * sizeof(int));
    return stack;
}

int is_empty(Stack *stack)
{
    return (stack->top == -1);
}

int is_full(Stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

void double_stack(Stack *stack)
{
    stack->capacity *= 2;
    stack->array = realloc(stack->array, stack->capacity * sizeof(int));
}

int capacity(Stack *stack)
{
    return stack->capacity;
}

void push(Stack *stack, int data)
{
    if (is_full(stack))
    {
        double_stack(stack);
    }

    stack->array[++stack->top] = data;
}

int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Error: Popping from empty stack.\n");
        return -1; // Indicate error
    }

    return (stack->array[stack->top--]);
}

void delete_stack(Stack *stack)
{
    if (stack)
    {
        if (stack->array)
        {
            free(stack->array);
        }
        free(stack);
    }
}
