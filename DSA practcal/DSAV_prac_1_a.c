#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int arrSize;
  printf("Enter size of array: ");
  scanf("%d",&arrSize);
  int *arr = (int*)malloc(arrSize* sizeof(int));

  for(int i=0;i<arrSize;i++)
  {
    int value;
    printf("Enter value at index %d: ",i);
    scanf("%d",&value);
    arr[i] = value;
  }

  for(int i=0;i<arrSize;i++)
  {
    printf("value at index %d: %d \n",i,arr[i]);
  }
  free(arr);
  return 0;
}
