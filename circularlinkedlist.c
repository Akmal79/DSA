#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularLinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct CircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = list->head;
    }
}

void insertBeginning(struct CircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        newNode->next = list->head;
        current->next = newNode;
        list->head = newNode;
    }
}

void deleteNode(struct CircularLinkedList* list, int value) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* current = list->head;
    struct Node* prev = NULL;

    do {
        if (current->data == value) {
            break;
        }
        prev = current;
        current = current->next;
    } while (current != list->head);

    if (current == list->head && current->next == list->head) {
        list->head = NULL;
    } else if (current == list->head) {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        list->head = current->next;
        temp->next = list->head;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }

    printf("Node with value %d deleted.\n", value);
}
void displayList(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

int main() {
    struct CircularLinkedList circularList;
    circularList.head = NULL;

    while (1) {
        int choice;
        printf("\nChoose an operation:\n1. Insert at End\n2. Insert at Beginning\n3. Delete Node\n4. Display List\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int dataEnd;
                printf("Enter data for insertion at end: ");
                scanf("%d", &dataEnd);
                insertEnd(&circularList, dataEnd);
                break;
            }
            case 2: {
                int dataBeginning;
                printf("Enter data for insertion at beginning: ");
                scanf("%d", &dataBeginning);
                insertBeginning(&circularList, dataBeginning);
                break;
            }
            case 3: {
                int dataDelete;
                printf("Enter data to delete: ");
                scanf("%d", &dataDelete);
                deleteNode(&circularList, dataDelete);
                break;
            }
            case 4:
                displayList(&circularList);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
