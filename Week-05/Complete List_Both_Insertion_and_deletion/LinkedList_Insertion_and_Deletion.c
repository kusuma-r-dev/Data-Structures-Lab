#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertEnd(struct Node **head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteFromFirst(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = *head;
    *head = temp->next;

    free(temp);
}

void deleteFromEnd(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node **head, int position) {
    struct Node *temp, *nextNode;
    int i;

    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        deleteFromFirst(head);
        return;
    }

    temp = *head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    nextNode = temp->next;
    temp->next = nextNode->next;

    free(nextNode);
}

void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void freeList(struct Node **head) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n--- DELETION OPERATIONS ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete at Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                deleteFromFirst(&head);
                break;

            case 3:
                deleteFromEnd(&head);
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 5:
                display(head);
                break;

            case 6:
                freeList(&head);
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
