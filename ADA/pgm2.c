//ADA PROGRAM 2

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(long int arr[], long int low, long int mid, long int high)
{
  long int k=low;
  long int i=low;
  long int j=mid+1;
  long int temp[100000];
  while(i<=mid && j<=high)
  {
    if(arr[i]<=arr[j])
    {
      temp[k]=arr[i];
      i++;
      k++;
    }
    else
    {
      temp[k]=arr[j];
      j++;
      k++;
    }
  }
  while(i<=mid)
  {
    temp[k]=arr[i];
    i++;
    k++;
  }
  while(j<=high)
  {
    temp[k]=arr[j];
    j++;
    k++;
  }
  for(i=low; i<=high; i++)
  arr[i]=temp[i];
}
void mergesort(long int arr[], long int low, long int high)
{
  if(low<high)
  {
    long int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}
int main()
{
  long int n=10000;
  int it=0;
  double time[10];
  printf("A_size,Merge\n");
  while(it++<10)
  {
    long int arr[n];
    for(int i=0; i<n; i++)
    {
      long int num=rand()%n+1;
      arr[i]=num;
    }
    clock_t start, end;
    start=clock();
    mergesort(arr,0,n-1);
    end=clock();
    time[it]=((double)(end-start))/CLOCKS_PER_SEC;
    printf("%li, %f\n", n, time[it]);
    n+=10000;
  }
  return 0;
}