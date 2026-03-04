#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

int main() {
    int n, m, i, value;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        pop();
    }
    
    for (i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    
    return 0;
}