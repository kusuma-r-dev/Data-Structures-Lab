#include<stdio.h>
#define MAX 5
int queue[MAX];
int rear = -1;
int front = -1;

void enqueue(int value)
{
    if(front == (rear + 1)%MAX) {
        printf("Queue Overflow\n");
        return;
    }
    else if(front == -1)
        front = 0;
    rear = (rear + 1)%MAX;
    queue[rear] = value;
}
void dequeue()
{
    if(front == -1){
        printf("Queue Underflow\n");
        return;
    }
    printf("%d has been dequeued\n",queue[front]);
    if(front == rear){
        front = rear = -1;
    }
    else
        front = (front + 1)%MAX;
}
void display()
{
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue contains : \n");
    while(1){
        printf("%d\t",queue[i]);
        if(i == rear)
            break;
        i = (i + 1)%MAX;
    }
}

int main()
{
    int choice, value;
    do
    {
        printf("\nSelect from the menu : \n1 - Insert a value into the queue\n2 - Dequeue the queue\n3 - Display the content of queue\n4 - Exit the program\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1 :
                printf("Enter a value to enqueue : ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2 :
                dequeue();
                break;
            case 3 :
                display();
                break;
            case 4 :
                printf("Exitting the program !!");
                break;
            default :
                printf("Invalid choice. Try again!!");
                break;
        }
    }while(choice != 4);
}
