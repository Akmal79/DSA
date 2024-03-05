#include <stdio.h>
#define MAX 100
void enQueue(int);
void deQueue();
void display();
int isfull();
int isempty();
int queue[MAX], front = -1, rear = -1;
void main()
{
    int value, choice;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            enQueue(value);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}
int isempty()
{
    if (front == -1 || front == rear + 1)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if (rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enQueue(int value)
{
    if (isfull())
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("\nInsertion success!!!");
    }
}

void deQueue()
{
    if (isempty())
    {
        printf("Queue underflow\n ");
    }
    else
    {

        printf("\nDeleted : %d", queue[front]);
        front++;
    }
}
void display()
{
    if (isempty())
    {
        printf("\nQueue is Empty!!!");
    }
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d\n", queue[i]);
    }
}
