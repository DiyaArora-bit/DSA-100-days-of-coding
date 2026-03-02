#include <stdio.h>
#include <stdlib.h>


struct Node {
    int coeff;
    int exp;
    struct Node* next;
};


struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}


struct Node* insert(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}


void display(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        }
        else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        }
        else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }
}


int main() {
    struct Node* head = NULL;
    int n, coeff, exp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }

    display(head);

    return 0;
}