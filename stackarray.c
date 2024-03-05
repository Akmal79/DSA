#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack {
    int capacity;
    int* array;
    int top;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

int is_full(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int item) {
    if (is_full(stack)) {
        printf("Stack Overflow: Cannot push, the stack is full.\n");
    } else {
        stack->top++;
        stack->array[stack->top] = item;
        printf("Pushed %d to the stack\n", item);
    }
}

int pop(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow: Cannot pop, the stack is empty.\n");
        return -1;
    } else {
        int item = stack->array[stack->top];
        stack->top--;
        printf("Popped %d from the stack\n", item);
        return item;
    }
}

void display(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->array[i]);
        }
    }
}

int main() {
    struct Stack* myStack = createStack(MAX_SIZE);
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

    free(myStack->array);
    free(myStack);

    return 0;
}
