#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    int i = index;
    
    while (hashTable[i] != 0 && hashTable[i] != -1) {
        i = (i + 1) % SIZE;  // linear probing
        if (i == index) {
            printf("Hash table overflow\n");
            return;
        }
    }
    hashTable[i] = key;
}

void display() {
    int i;
    printf("Hash Table: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int main() {
    int i;
    for (i = 0; i < SIZE; i++) hashTable[i] = 0;
    
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    
    display();
    return 0;
}
