#include<stdio.h>

int top = -1;
int isStackOverflow()
{
    return (top == 10) ? 1 : 0;
}

int isStackUnderflow()
{
    return (top == -1) ? 1 : 0;
}

void push(int arr[], int n)
{
    if(isStackOverflow())
    {
        printf("Stack is Overflow.\n");
    }
    else
    {
        int value;
        printf("Enter value: ");
        scanf("%d",&value);
        arr[top+1] = value;
        top++;
        printf("Element Inserted.\n");
    }    
}

void pop(int arr[], int n)
{
    if(isStackUnderflow())
    {
        printf("Stack is Underflow.\n");
    }
    else
    {
        printf("Element %d Removed.\n", arr[top]);
        top--;
    }
}

void peep(int arr[],int n)
{
    if(isStackUnderflow())
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("\nTop: %d\n", arr[top]);
    }
}

void change(int arr[], int n)
{
    if(isStackUnderflow())
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        int value;
        printf("Enter value to Change: ");
        scanf("%d",&value);
        arr[top] = value;
    }

}

void display(int arr[])
{
    if(isStackUnderflow())
    {
        printf("Stack is Empty.\n");
    }
    else
    {   
        printf("\nCurrent Stack is : \n");
        for(int i=0;i<=top;i++)
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
        printf("\n--- Stack opration. \n1) Insert(PUSH). \n2) Delete(POP). \n3) PEEP. \n4) CHANGE. \n5) DISPLAY. \n6) Exit \nEnter choice : ");
        scanf("%d",&choice);
        if(choice == 1) { push(arr, 10); }
        else if(choice == 2) { pop(arr, 10); }
        else if(choice == 3) { peep(arr, 10); }
        else if(choice == 4) { change(arr, 10); }
        else if(choice == 5) { display(arr); }
        else { break; }
    }
   return 0;
}
