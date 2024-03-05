PUSH OPERATION
#include <stdio.h>
#include <conio.h>
#define SIZE 10
    void
    push(int);
int a[SIZE], top = -1;
int main()
{
    int value;
    printf("Stack using array implementation ::\n");
    printf("Enter the value to be insert: ");
    scanf("%d", &value);
    push(value);
    return 0;
}
void push(int value)
{
    if (top == SIZE - 1)
        printf("\nStack is Full!!! Insertion is not possible!!!");
    else
    {
        top++;
        a[top] = value;
        printf("\nInsertion success!!!");
    }
}
CREATE A STACK OF ELEMENTS
#include <stdio.h>
#include <conio.h>
#define SIZE 10
    void
    push(int);
int a[SIZE], top = -1;

int main()
{
    int value, n;
    printf("Stack using array implementation :\n");
    printf("Input number of elements: ");
    scanf("%d", &n);
    printf("Creating a stack with %d elements:\n", n);
    printf("Enter the values to insert:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        push(value);
    }
    return 0;
}
void push(int value)
{
    if (top == SIZE - 1)
        printf("\nStack is Full!!! Insertion is not possible!!!\n");
    else
    {
        top++;
        a[top] = value;
        printf("\nInsertion success!!!\n");
    }
}
DISPLAY OPERATION
#include <stdio.h>
#include <conio.h>
#define SIZE 10
    void
    push(int);
void display();
int a[SIZE], top = -1;
int main()
{
    int value, n;

    printf("Stack using array implementation :\n");
    printf("Create a stack of 'n' elements: \n");
    scanf("%d", &n);
    printf("Enter the %d value to insert:\n", n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        push(value);
    }
    display();
    return 0;
}
void push(int value)
{
    if (top == SIZE - 1)
        printf("\nStack is Full!!! Insertion is not possible!!!\n");
    else
    {
        top++;
        a[top] = value;
        printf("\nInsertion success!!!\n");
    }
}
void display()
{
    if (top == -1)
        printf("\nStack is Empty!!!");
    else
    {
        int i;
        printf("Displaying stack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", a[i]);
    }
}
POP OPERATION
#include <stdio.h>
#include <conio.h>

#define SIZE 10
    void
    push(int);
int a[SIZE], top = -1;
int main()
{
    int value, n;
    printf("Stack using array implementation:\n");
    printf(“Input number of elements”)
        scanf("%d", &n);
    printf("Creating a stack with %d elements: \n", n);
printf("Enter the values to insert:\n”);
for(int i=1;i<=n;i++)
{
        scanf("%d", &value);
        push(value);
}
display();
pop();
display();
return 0;
}
void push(int value)
{
    if (top == SIZE - 1)
        printf("\nStack is Full!!! Insertion is not possible!!!");
    else
    {
        top++;
        a[top] = value;
        printf("\nInsertion success!!!");
    }
}
void pop()
{
    if (top == -1)
        printf("\nStack is Empty!!! Deletion is not possible!!!");

    else
    {
        printf("\nDeleted : %d", a[top]);
        top--;
    }
}
void display()
{
    if (top == -1)
        printf("\nStack is Empty!!!");
    else
    {
        int i;
        printf("Displaying stack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", a[i]);
    }
}
