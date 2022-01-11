#include<stdio.h>

int main(void)
{
    int value;
    int arr[7] = {5,7,6,4,6,86,5};

    printf("Enter value to find: ");
    scanf("%d",&value);

    int flag = 0;
    for(int i=0;i<7;i++)
    {
        if(arr[i] == value)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        printf("[+] value found.");
    }
    else
    {
        printf("[-] value not found.");
    }

    return 0;
}