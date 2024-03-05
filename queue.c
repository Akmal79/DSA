#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int is_empty(struct Queue* queue) {
    return (queue->front == -1);
}

int is_full(struct Queue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enqueue(struct Queue* queue, int item) {
    if (is_full(queue)) {
        printf("Queue Overflow: Cannot enqueue, the queue is full.\n");
    } else {
        if (is_empty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        printf("Enqueued %d to the queue\n", item);
    }
}
int dequeue(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue Underflow: Cannot dequeue, the queue is empty.\n");
        return -1;
    } else {
        int item = queue->array[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->capacity;
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
        int i = queue->front;
        do {
            printf("%d\n", queue->array[i]);
            i = (i + 1) % queue->capacity;
        } while (i != (queue->rear + 1) % queue->capacity);
    }
}

int main() {
    struct Queue* myQueue = createQueue(MAX_SIZE);
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

    free(myQueue->array);
    free(myQueue);

    return 0;
}
