#include<stdio.h>
struct node
{
int priority;
int data;
struct node *link;
}*front=NULL;
int main()
{
int priority,data;
for(int i=0;i<5;i++)
{
scanf("%d %d",&data, &priority);
printf(" priority is: %d and data is: %d ",data, priority);
enqueue(data, priority);
}
display();
return 0;
}
int isEmpty()
{
if(front==NULL)
{
return 1;
}
else{
return 0;
}
}

void enqueue(int data, int priority)
{

struct node* temp = NULL;
struct node* newNode = (struct node*) malloc(sizeof(struct node));
if (newNode == NULL)
{
printf( "Memory not available. \n");
exit(1);
}
newNode->priority = priority;
newNode->data = data;
newNode->link = NULL;
if (isEmpty()|| priority < front -> priority)
{
newNode->link = front;
front = newNode;
}
else
{
temp = front;
while(temp->link != NULL && temp->link->priority <= priority)
{
temp = temp->link;
}
newNode->link = temp->link;
temp->link=newNode;
}
printf("insertion success \n");
}

void display()
{
if(isEmpty())
{
printf("queue is full");
}
else
{
struct node *temp=front;

printf("queue values are: ");
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->link;
}
}
}
ENQUEUE, DEQUEUE AND DISPLAY FUNCTION
#include<stdio.h>
struct node
{
int priority;
int data;
struct node *link;
}*front=NULL;
int main()
{
int priority,data;
for(int i=0;i<5;i++)
{
scanf("%d %d",&data, &priority);
printf(" priority is: %d and data is: %d ",data, priority);
enqueue(data, priority);
}
display();
dequeue();
display();
return 0;
}
int isEmpty()
{
if(front==NULL)
{
return 1;

}
else{
return 0;
}
}
void enqueue(int data, int priority)
{
struct node* temp = NULL;
struct node* newNode = (struct node*) malloc(sizeof(struct node));
if (newNode == NULL)
{
printf( "Memory not available. \n");
exit(1);
}
newNode->priority = priority;
newNode->data = data;
newNode->link = NULL;
if (isEmpty()|| priority < front -> priority)
{
newNode->link = front;
front = newNode;
}
else
{
temp = front;
while(temp->link != NULL && temp->link->priority <= priority)
{
temp = temp->link;
}
newNode->link = temp->link;
temp->link=newNode;
}
printf("insertion success \n");
}
void display()
{
if(isEmpty())

{
printf("queue is empty");
}
else
{
struct node *temp=front;
printf("queue values are: ");
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->link;
}
printf("\n");
}
}
void dequeue()
{
int data;
struct node *temp;
if(isEmpty())
{
printf("queue is empty");
}
else
{
temp=front;
data=temp->data;
front=front->link;
printf("data deleted is: %d \n",temp->data);
free(temp);
temp=NULL;
}
}
