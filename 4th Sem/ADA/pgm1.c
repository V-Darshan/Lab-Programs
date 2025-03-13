#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void sort(int a[],int n){
    int min,i,j,temp;
    for (i = 0; i < n-2; i++){
        min=i;
        for(j=i+1;j<n-1;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    
}
int main(){
    int a[10000],i,n;
    printf("Enter the valueof n: ");
    scanf("%d",&n);
    for(int a[10000];i<n;i++){
        a[i]=rand()%100;
    }
    clock_t start=clock();
    sort(a,n);
    clock_t end=clock();
    double timetaken=((double)(end-start));
    printf("Time taken to sort %d elements %f seconds\n",n,timetaken);
    return 0;
}