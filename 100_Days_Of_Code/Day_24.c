#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i, key;
    struct node *head = NULL, *temp = NULL, *newnode, *prev = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d", &key);

    temp = head;

    while(temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp) {
        if(prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}