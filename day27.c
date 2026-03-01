#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}


int findIntersection(struct Node* head1, struct Node* head2) {
    struct Node *temp1, *temp2;

    for(temp1 = head1; temp1 != NULL; temp1 = temp1->next) {
        for(temp2 = head2; temp2 != NULL; temp2 = temp2->next) {
            if(temp1->data == temp2->data) {
                return temp1->data;   
            }
        }
    }
    return -1; 
}

int main() {
    int n, m, result;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    result = findIntersection(head1, head2);

    if(result != -1)
        printf("%d\n", result);
    else
        printf("No Intersection\n");

    return 0;
}