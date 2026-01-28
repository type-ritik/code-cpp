#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack *create_stack();

void delete_stack(Stack *);

int is_full(Stack *);

int is_empty(Stack *);

void peek(Stack *);

void push(Stack *, int);

int pop(Stack *);

int main(void)
{
    Stack *stack = create_stack();

    peek(stack);
    push(stack, 5);
    peek(stack);
    push(stack, 1);
    peek(stack);
    push(stack, 2);
    peek(stack);
    push(stack, 3);
    peek(stack);
    push(stack, 4);
    peek(stack);
    push(stack, 9);
    printf("\nPop %d\n", pop(stack));
    peek(stack);
    printf("Pop %d\n", pop(stack));
    peek(stack);
    printf("Pop %d\n", pop(stack));
    peek(stack);
    printf("Pop %d\n", pop(stack));
    peek(stack);
    delete_stack(stack);

    return 0;
}

Stack *create_stack()
{
    Stack *stack = malloc(sizeof(Stack));

    if (!stack)
    {
        printf("Error: Creating stack!");
        return NULL;
    }

    stack->top = -1;
    stack->capacity = MAXSIZE;
    stack->array = malloc(stack->capacity * sizeof(int));

    return stack;
}

int is_full(Stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

void peek(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top: %d\n", stack->array[stack->top]);
}

int is_empty(Stack *stack)
{
    return (stack->top == -1);
}

void push(Stack *stack, int data)
{
    if (is_full(stack))
    {
        printf("Stack Overflow!");
        return;
    }

    stack->array[++stack->top] = data;
    return;
}

int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack Underflow!");
        return -1;
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
