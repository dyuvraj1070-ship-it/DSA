#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* advance(struct Node* head, int diff) {
    while (diff-- && head)
        head = head->next;
    return head;
}

int main() {
    int n, m, i, val;

    scanf("%d", &n);
    int *arr1 = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int *arr2 = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL, *common = NULL;

    for (i = n - 1; i >= 0; i--) {
        struct Node* newNode = createNode(arr1[i]);
        newNode->next = head1;
        head1 = newNode;
    }

    int intersectIndex = -1;
    for (i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr2[i] == arr1[j]) {
                intersectIndex = j;
                break;
            }
        }
        if (intersectIndex != -1)
            break;
    }

    for (i = m - 1; i >= 0; i--) {
        if (intersectIndex != -1 && i >= (m - (n - intersectIndex)))
            continue;
        struct Node* newNode = createNode(arr2[i]);
        newNode->next = head2;
        head2 = newNode;
    }

    if (intersectIndex != -1) {
        temp = head1;
        for (i = 0; i < intersectIndex; i++)
            temp = temp->next;
        common = temp;

        struct Node* last = head2;
        if (last == NULL)
            head2 = common;
        else {
            while (last->next)
                last = last->next;
            last->next = common;
        }
    }

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1, *ptr2 = head2;

    if (len1 > len2)
        ptr1 = advance(ptr1, len1 - len2);
    else
        ptr2 = advance(ptr2, len2 - len1);

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) {
            printf("%d\n", ptr1->data);
            free(arr1);
            free(arr2);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");

    free(arr1);
    free(arr2);
    return 0;
}