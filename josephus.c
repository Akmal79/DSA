#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;
// Function to create a circular linked list with n nodes
void createCircularList(int n) 
{
    int data;
    for (int i = 1; i <= n; i++) 
    {
        printf(" Input data for node %d : ", i);
        scanf("%d", &data);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
}
// Function to display the circular linked list
void display() 
{
    struct node *current = head;
    if (head == NULL) 
    {
        printf("List is empty");
    } 
    else 
    {
        printf("Nodes of the circular linked list: \n");
        do 
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }
}
// Function to perform Josephus elimination
int josephus(int k) 
{
    struct node *current = head;
    struct node *prev = tail;
    while (head->next != head) 
    {
        // Move k-1 steps
        for (int i = 0; i < k - 1; i++) 
        {
            prev = current;
            current = current->next;
        }
        // Eliminate the k-th soldier
        prev->next = current->next;
        if (current == head) 
        {
            head = current->next; // Update head if the eliminated soldier is the head
        }
        int eliminated = current->data;
        free(current);
        // Update current and prev for the next round
        current = prev->next;
        prev = current;
    }
    int winner = head->data;
    free(head);
    head = NULL;
    return winner;
}

int main() 
{
    int n, k;
    printf(" Input the number of soldiers : ");
    scanf("%d", &n);
    printf(" Input the step size (k) : ");
    scanf("%d", &k);
    printf("......................... \n");
    printf(" Create a circular linked list \n");
    createCircularList(n);
    display();
    printf("......................... \n");
    printf(" Josephus Elimination \n");
    int winner = josephus(k);
    printf("The last surviving soldier is: %d\n", winner);
    return 0;
}
