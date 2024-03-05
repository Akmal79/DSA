#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

enum ProbingType {
    LINEAR,
    QUADRATIC
};

struct HashTable {
    int* array;
    int size;
    enum ProbingType probing;
};

struct HashTable* createHashTable(int size, enum ProbingType probing) {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
    table->size = size;
    table->probing = probing;
    table->array = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        table->array[i] = -1;
    }

    return table;
}

int hashFunction(int key, int size) {
    return key % size;
}

int linearProbe(int index, int size, int attempt) {
    return (index + attempt) % size;
}

int quadraticProbe(int index, int size, int attempt) {
    return (index + attempt * attempt) % size;
}

void insert(struct HashTable* table, int key) {
    int index = hashFunction(key, table->size);
    int attempt = 0;

    while (table->array[index] != -1) {
        if (table->probing == LINEAR) {
            index = linearProbe(index, table->size, attempt);
        } else if (table->probing == QUADRATIC) {
            index = quadraticProbe(index, table->size, attempt);
        }
        attempt++;
    }

    table->array[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

int search(struct HashTable* table, int key) {
    int index = hashFunction(key, table->size);
    int attempt = 0;
    while (table->array[index] != -1) {
        if (table->array[index] == key) {
            printf("%d found at index %d\n", key, index);
            return index;
        }
        if (table->probing == LINEAR) {
            index = linearProbe(index, table->size, attempt);
        } else if (table->probing == QUADRATIC) {
            index = quadraticProbe(index, table->size, attempt);
        }
        attempt++;
    }
    printf("%d not found in the hash table\n", key);
    return -1;
}
void delete(struct HashTable* table, int key) {
    int index = search(table, key);

    if (index != -1) {
        table->array[index] = -1;
        printf("Deleted %d from index %d\n", key, index);
    }
}
void displayHashTable(struct HashTable* table) {
    printf("Hash Table:\n");
    for (int i = 0; i < table->size; i++) {
        printf("[%d] ", i);
        if (table->array[i] != -1) {
            printf("%d", table->array[i]);
        }
        printf("\n");
    }
}

int main() {
    struct HashTable* myTable = createHashTable(SIZE, QUADRATIC);

    insert(myTable, 5);
    insert(myTable, 15);
    insert(myTable, 25);
    insert(myTable, 35);
    insert(myTable, 45);

    displayHashTable(myTable);

    search(myTable, 15);
    search(myTable, 55);

    delete(myTable, 15);

    displayHashTable(myTable);

    free(myTable->array);
    free(myTable);

    return 0;
}
