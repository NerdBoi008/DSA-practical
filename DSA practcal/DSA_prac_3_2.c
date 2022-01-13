#include<stdio.h>

void binarySearch(int arr[], int len, int value)
{
	int right = len, left = 0, mid, flag = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if(arr[mid] == value)
		{
			flag = 1;
			break;
		}
		if(arr[mid] > value)
		{
			right = mid -1;
		}
		else
		{
			left = mid + 1;
		}
	}
	(flag == 1) ? printf("[+] value found.") : printf("[-] value not found.");
}

int main(void)
{
	int value;
	int arr[10] = {2,5,8,13,15,22,25,27,30,37};
	printf("Enter Value to find: ");
	scanf("%d",&value);

	binarySearch(arr, 10, value);
	return 0;
}
