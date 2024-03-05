#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int is_empty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if (is_empty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d to the queue\n", item);
}

int dequeue(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue Underflow: Cannot dequeue, the queue is empty.\n");
        return -1;
    } else {
        struct Node* temp = queue->front;
        int item = temp->data;
        queue->front = temp->next;
        free(temp);
        if (queue->front == NULL) {
            // If the last element is dequeued, update rear to NULL
            queue->rear = NULL;
        }
        printf("Dequeued %d from the queue\n", item);
        return item;
    }
}

void display(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        struct Node* current = queue->front;
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

int main() {
    struct Queue* myQueue = createQueue();
    int choice, item;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(myQueue, item);
                break;

            case 2:
                dequeue(myQueue);
                break;

            case 3:
                display(myQueue);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free the memory used by the linked list nodes
    struct Node* current = myQueue->front;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    // Free the memory used by the queue structure
    free(myQueue);

    return 0;
}
    