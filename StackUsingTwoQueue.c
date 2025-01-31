#include <stdio.h>
#include <stdlib.h>

#define Size 1000

typedef struct Queue
{
    int rear;
    int front;
    int capacity;
    int *Arr;
} Queue;

Queue *createQueue(int capacity)
{

    Queue *Queue = malloc(sizeof(Queue));
    Queue->capacity = capacity;
    Queue->rear = Queue->front = -1;
    Queue->Arr = (int *)malloc(capacity * sizeof(int));
    return Queue;
}
int isfull(Queue *q, int capacity)
{
    return q->rear == capacity - 1;
}

int isempty(Queue *q)
{
    return q->front == -1;
}

void Enqueue(Queue *Q,int val)
{

    if (isfull(Q, Size))
    {
        printf("Queue is Full\n");
        return;
    }
   
    if (Q->front == -1)
    {
        Q->front = 0;
    }

    Q->Arr[++Q->rear] = val;
}

int Dequeue(Queue *Q)
{
    if (isempty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = Q->Arr[Q->front];
    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
    }
    else
    {
        Q->front++;
    }
    return value;
}

void push(Queue *q1, Queue *q2, int val)
{
    Enqueue(q1, val);
    while (!isempty(q2))
    {
        Enqueue(q1, Dequeue(q2));
    }
}

void pop(Queue *q)
{
    if (isempty(q))
    {
        printf("Stack is empty!\n");
        return ;
    }
    int popped_value = q->Arr[q->front];
    Dequeue(q);
}
void peek(Queue *q)
{
    if (isempty(q))
    {
        printf("Stack is empty!\n");
        return ;
    }
    printf("The Top element is : %d", q->Arr[q->front]);
}
void display(Queue *q)
{
    if (isempty(q))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d\n", q->Arr[i]);
    }
}

int main()
{

    Queue *q1 = createQueue(Size);
    Queue *q2=createQueue(Size);

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
        int val;
        printf("Enter the value to push: ");
        scanf("%d",&val);
        push(q1,q2,val);
            break;
        case 2:
            pop(q1);
            break;
        case 3:
            peek(q1);
            break;
        case 4:
            display(q1);
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