#include <stdio.h>

int queue[100], front = 0, rear = -1;
int stack[100], top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    while (front <= rear) {
        push(dequeue());
    }

    while (top != -1) {
        enqueue(pop());
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}