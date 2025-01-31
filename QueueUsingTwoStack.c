#include <stdio.h>
#include <stdlib.h>

#define Size 1000

int count=0;

typedef struct stack
{
    int top;
    int capacity;
    int *arr;
}stack;

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
void push(stack *s1,int val)
{

    if (isfull(s1, Size))
    {
        printf("Stack is Full\n");
        return;
    }
    s1->arr[++s1->top] = val;
}

int  pop(stack *s1)
{
    if (isempty(s1))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s1->arr[s1->top--];
}

void enqueue(stack* s1,int  val){
    push(s1,val);
    count++;
}

void dequeue(stack *s1,stack *s2){
        if(isempty(s1)){
            printf("queue is Empty");
            return;
        }

        for(int i=0;i<count;i++){
            push(s2,pop(s1));
        }
        printf("Dequeued : %d\n",pop(s2));
        count--;
        for(int i=0;i<count;i++){
            push(s1,pop(s2));
        }
}

void display(stack* s1){
    printf("Queue elements : \n");
        for(int i=0;i<s1->top;i++){
            printf("%d ",s1->arr[i]);
        }
    printf("\n");
}

void frontElement(stack *s1, stack *s2) {
    if (isempty(s1)) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        push(s2, pop(s1));
    }
 printf("Front Element: %d\n", s2->arr[s2->top]);
    for (int i = 0; i < count; i++) {
        push(s1, pop(s2));
    }
}
void rearElement(stack *s1) {
    if (isempty(s1)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Rear Element: %d\n", s1->arr[s1->top]);
}

int main()
{
     stack* s1 = createStack(Size);
    stack* s2= createStack(Size);

    while (1)
    {
        int ch;
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Front Element\n");
        printf("4.Rear Element\n");
        printf("5.show\n");
        printf("6.Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
             int val;
            printf("Enter value to enqueue: ");
             scanf("%d", &val);
             enqueue(s1, val);
            break;
        case 2:
            dequeue(s1,s2);
            break;
        case 3:
            frontElement(s1,s2);
            break;
        case 4:
            rearElement(s1);
            break;
        case 5:

            display(s1);
            break;
        case 6:
            break;
        default:
            printf("invalid choice\n");
            break;
        }
        if (ch == 6)
        {
            return 0;
        }
    }

    return 0;
}