#include<stdio.h>

int front = -1, rear = -1;

int isQueueUnderflow()
{
    return (front == -1 || front > rear) ? 1 : 0;
}

int isQueueOverflow()
{
    return (rear == 10) ? 1 : 0;
}

void enqueue(int arr[])
{
    if(isQueueOverflow())
    {
        printf("\nQueue is Overflow.\n");
    }
    else
    {
        if(front == -1) { front = 0; }
        int value;
        printf("\nEnter value to Insert: ");
        scanf("%d",&value);
        arr[rear+1] = value;
        rear++;
        printf("Element Inserted.\n");
    }
}

void dequeue(int arr[])
{
    if(isQueueUnderflow())
    {
        printf("\nQueue is Underflow.\n");
    }
    else
    {
        printf("Element %d Removed.\n", arr[front]);
        front++;
    }
}

void display(int arr[])
{
    if(isQueueUnderflow())
    {
        printf("\nQueue is Underflow.\n");
    }
    else
    {
        for(int i = front; i<= rear; i++)
        {
            printf("Index %d : %d \n",i,arr[i]);
        }
    }
}

int main(void)
{
    int arr[10], choice;
    while (1)
    {
        printf("\n--- Queue Operation. --- \n1) Insert. \n2) Delete. \n3) Display. \n4) Exit. \nEnter choice: ");
        scanf("%d",&choice);
        if(choice == 1) { enqueue(arr); }
        else if(choice == 2) { dequeue(arr); }
        else if(choice == 3) { display(arr); }
        else { break; }
    }  
    return 0;
} 