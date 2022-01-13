#include<stdio.h>

void printArray(int arr[], int n)
{
    printf(" Sorted Array. \n [ ");
    for(int i=0;i<10;i++)
    {
        printf("%d, ",arr[i]);
    } printf(" ]");
}

void bubbleSort(int arr[], int n)
{
    int swap;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
    printArray(arr, n);
}

void insertionSort(int arr[], int n)
{
    int key, j;
    for(int i=0;i<n;i++)
    {
       key = arr[i] ;
       j = i-1;
       while(j>=0 && arr[j]>key) 
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
    }
    printArray(arr, n);
}

void selectionSort(int arr[], int n)
{
    int i, j, positon, swap;
    for(int i=0;i<n-1;i++)
    {
        positon = i;
        for(int j= i+1;j<n;j++)
        {
            if(arr[positon] > arr[j])
            {
                positon = j;
            }
        }
        if(positon != i)
        {
            swap = arr[i];
            arr[i] = arr[positon];
            arr[positon] = swap;
        }
    }
    printArray(arr, n);
}

int main(void)
{
    int choice;
    int arr[10] = {12,32,8,55,78,2,5,31,43,5};

    printf("\n --- Sorting --- \n 1) Bubble sort. \n 2) Insertion sort. \n 3) Selection sort. \n Enter choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        bubbleSort(arr,10);
        break;
    
    case 2:
        insertionSort(arr, 10);
        break;
    
    case 3:
        selectionSort(arr, 10);
        break;

    default:
        printf("Invalid Input.");
        break;
    }
    return 0;
}