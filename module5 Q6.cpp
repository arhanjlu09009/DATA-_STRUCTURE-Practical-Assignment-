#include <stdio.h>
#define SIZE 7

int hashTable[SIZE] = {0};

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    hashTable[index] = key;
}

void display() {
    printf("Hash Table: ");
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int main() {
    insert(23);
    insert(43);
    insert(13);
    insert(89);
    
    display();
    return 0;
}
