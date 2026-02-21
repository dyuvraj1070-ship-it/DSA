#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        // Create new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;   // First node
        } else {
            temp->next = newNode;  // Link previous node
        }

        temp = newNode;
    }

    // Traverse and print linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}