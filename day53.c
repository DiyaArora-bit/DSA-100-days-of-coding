#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}

struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    struct QNode arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[++q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    int min = 0, max = 0;

    int map[2000][200];
    int count[2000] = {0};

    enqueue(&q, root, 1000);

    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct Node* node = temp.node;
        int hd = temp.hd;

        map[hd][count[hd]++] = node->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left) enqueue(&q, node->left, hd - 1);
        if (node->right) enqueue(&q, node->right, hd + 1);
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}