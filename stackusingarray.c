#include <stdio.h>
#include <stdlib.h>

#define Size 1000

typedef struct stack
{
    int top;
    int capacity;
    int *arr;
} stack;

stack *createStack(int capacity)
{

    stack *stack = malloc(sizeof(stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = malloc(capacity * sizeof(int));
    return stack;
}

int isfull(stack *s, int capacity)
{
    return s->top == capacity - 1;
}

int isempty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(stack *s)
{

    if (isfull(s, Size))
    {
        printf("Stack is Full\n");
        return;
    }
    int val;
    printf("Enter The value to Be Pushed : ");
    scanf("%d", &val);
    s->arr[++s->top] = val;
}

void pop(stack *s)
{
    if (isempty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    s->top--;
}

void peek(stack *s)
{
    if (isempty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("The Top Element Is : %d\n", s->arr[s->top]);
}
void show(stack *s)
{
    if (isempty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}

int main()
{

    stack *s = createStack(Size);

    while (1)
    {
        int ch;
        printf("\n1.push\n");
        printf("2.pop\n");
        printf("3.Top Element\n");
        printf("4.show\n");
        printf("5.Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            peek(s);
            break;
        case 4:
            show(s);
            break;
        case 5:
            break;
        default:
            printf("invalid choice\n");
            break;
        }
        if (ch == 5)
        {
            return;
        }
    }
    return 0;
}
