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

void Enque(Queue *Q)
{

    if (isfull(Q, Size))
    {
        printf("Queue is Full\n");
        return;
    }
    int val;
    printf("Enter The Value to be Enqued in The Queue : ");
    scanf("%d", &val);
    if (Q->front == -1)
    {
        Q->front = 0;
    }

    Q->Arr[++Q->rear] = val;
}

void Dequeue(Queue *Q)
{
    if (isempty(Q))
    {
        printf("Queue is empty\n");
        return;
    }
    if (Q->front == Q->rear)
    {

        Q->front = Q->rear = -1;
    }
    else
    {
        Q->front++;
    }
}

void frontele(Queue *q)
{
    printf("The Front ELement Of The Queue Is : %d", q->Arr[q->front]);
}

void rearele(Queue *q)
{
    printf("The rear ELement Of The Queue Is : %d", q->Arr[q->rear]);
}

void show(Queue *q)
{
    printf("Queue Element are \n");
    for (int i = q->front; i <= q->rear; i++)
        printf("\n");
}

int main()
{

    Queue *q = createQueue(Size);

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
            Enque(q);
            break;
        case 2:
            Dequeue(q);
            break;
        case 3:
            frontele(q);
            break;
        case 4:
            rearele(q);
            break;
        case 5:

            show(q);
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