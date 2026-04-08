#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

struct Node* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(rootVal);

    if (inStart == inEnd) return root;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int* inorder = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}