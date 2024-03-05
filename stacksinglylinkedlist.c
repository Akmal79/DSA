PUSH OPERATION
#include <stdio.h>
#include <conio.h>
    void
    push(int);
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
void push(int);
int main()
{
    int value;
    printf("Stack using Linked List ::\n");
    printf("Enter the value to be insert: ");
    scanf("%d", &value);
    push(value);
    display();
    return 0;
}
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }
    top = newNode;
    printf("\nInsertion is Success!!!\n");
}
CREATE A STACK OF ELEMENTS
#include <stdio.h>
#include <conio.h>
    void
    push(int);
int main()
{
    int value, n;
    printf("Stack using Linked List ::\n");
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
return 0;
}
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
    printf("\nInsertion is Success!!!\n");
}
DISPLAY OPERATION

#include <stdio.h>
#include <conio.h>
    struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
void push(int);
void display();
int main()
{
    printf("Stack using Linked List ::\n");
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
}
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
    printf("\nInsertion is Success!!!\n");
}
void display()
{
    if (top == NULL)
        printf("\nStack is Empty!!!\n");
    else
    {
        printf("Displaying stack elements:\n");
        struct Node *temp = top;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}
POP OPERATION
#include <stdio.h>
#include <conio.h>
    struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
void push(int);
void display();
void pop();
int main()
{
    int value, n;
    printf("Stack using Linked List ::\n");
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
}
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
    printf("Insertion is Success!!!\n");
}
void display()
{
    if (top == NULL)
        printf("Stack is Empty!!!\n");
    else
    {
        printf("Displaying stack elements:\n");
        struct Node *temp = top;
        while (temp != NULL)
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
    }
}
void pop()
{

    if (top == NULL)
        printf("Stack is Empty!!!\n");
    else
    {
        struct Node *temp = top;
        printf("Deleted element: %d \n", temp->data);
        top = temp->next;
        free(temp);
    }
}
