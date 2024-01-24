#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// Function to enter values into linked list
void insertValueAtEnd(struct node** head, int value) {
    struct node* temp = createNode(value);
    if (*head == NULL) {
        *head = temp;
    } else {
        struct node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
}

// Function to enter value at the beginning of linked list
void insertValueAtBeginning(struct node** head, int value) {
    struct node* temp = createNode(value);
    temp->next = *head;
    *head = temp;
}

// Function to delete a specific value
void deleteValue(struct node** head, int value) {
    struct node *prev, *temp;
    prev = temp = *head;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in list\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insertValueAtEnd(&head, 5);
    insertValueAtEnd(&head, 38);
    insertValueAtEnd(&head, 3);
    insertValueAtEnd(&head, 22);

    printf("Inserted these numbers at the end\n");
    printList(head);

    insertValueAtBeginning(&head, 8);

    printf("Inserted this number in the beginning\n");
    printList(head);

    deleteValue(&head, 3);

    printf("Deleted 3 from list\n");
    printList(head);

    return 0;
}
