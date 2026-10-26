
#include <stdio.h>
#define Max 5

int queue[Max];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if (rear == Max - 1)
    {
        printf("Overflow\n");
        return;
    }
    else if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = val;
    printf("Element has been inserted!!\n");
}

void dequeue()
{
    int val;

    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        val = queue[front++];
        printf("\n%d has been dequeued!!\n", val);
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        printf("Queue contains:\n");

        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice, val;

    do
    {
        printf("\nEnter your choice:\n");
        printf("1 - Insert a value into the queue\n");
        printf("2 - Dequeue the queue\n");
        printf("3 - Display the values of the queue\n");
        printf("4 - Exit\n\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting the program!!\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
