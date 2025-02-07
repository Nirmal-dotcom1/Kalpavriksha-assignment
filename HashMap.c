#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node** entries;
} hash_table;

int hash(int key) {
    return key % TABLE_SIZE;
}

hash_table* create_hash_table() {
    hash_table* hashtable = (hash_table*)malloc(sizeof(hash_table));
    hashtable->entries = (Node**)malloc(TABLE_SIZE * sizeof(Node*));

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

Node* create_node(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(hash_table* ht, int key, int value) {
    int slot = hash(key); 
    Node* entry = ht->entries[slot];

    while (entry != NULL) {
        if (entry->key == key) {
            entry->value = value; 
            return;
        }
        entry = entry->next;
    }

    Node* newNode = create_node(key, value);
    newNode->next = ht->entries[slot];
    ht->entries[slot] = newNode;
}

int search(hash_table* ht, int key) {
    int slot = hash(key);
    Node* entry = ht->entries[slot];

    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }

    return -1;  
}

void delete(hash_table* ht, int key) {
    int slot = hash(key);
    Node* entry = ht->entries[slot];
    Node* prev = NULL;

    while (entry != NULL) {
        if (entry->key == key) {
            if (prev == NULL) {
                ht->entries[slot] = entry->next;  
            } else {
                prev->next = entry->next;
            }
            free(entry); 
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = entry;
        entry = entry->next;
    }

    printf("Key %d not found.\n", key);
}

void display(hash_table* ht) {
    printf("Hash Table:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* entry = ht->entries[i];
        if (entry != NULL) {
            printf("Index %d: ", i);
            while (entry != NULL) {
                printf("(%d, %d) -> ", entry->key, entry->value);
                entry = entry->next;
            }
            printf("NULL\n");
        }
    }
}
int main() {
    hash_table* hashtable = create_hash_table();

    int choice, key, value;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Insert Into Hash \n");
        printf("2. Search Key in Hash\n");
        printf("3. Delete from HashTable\n");
        printf("4. Display \n");
        printf("5. Exit From program\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(hashtable, key, value);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search(hashtable, key);
                if (value == -1) {
                    printf("Key %d not found.\n", key);
                } else {
                    printf("Value: %d\n", value);
                }
                break;

            case 3:
                printf("Enter the key you want to delete: ");
                scanf("%d", &key);
                delete(hashtable, key);
                break;

            case 4:
                display(hashtable);
                break;

            case 5:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice, Enter correct Choice \n");
        }
    }

    return 0;
}
