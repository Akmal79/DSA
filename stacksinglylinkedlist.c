#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int is_empty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d to the stack\n", item);
}

int pop(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow: Cannot pop, the stack is empty.\n");
        return -1;
    } else {
        struct Node* temp = stack->top;
        int item = temp->data;
        stack->top = temp->next;
        free(temp);
        printf("Popped %d from the stack\n", item);
        return item;
    }
}

void display(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        struct Node* current = stack->top;
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

int main() {
    struct Stack* myStack = createStack();
    int choice, item;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(myStack, item);
                break;

            case 2:
                pop(myStack);
                break;

            case 3:
                display(myStack);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free the memory used by the linked list nodes
    struct Node* current = myStack->top;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    // Free the memory used by the stack structure
    free(myStack);

    return 0;
}
