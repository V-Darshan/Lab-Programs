#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Swap utility
void swap(long int* a, long int* b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
// Selection sort
void selectionSort(long int arr[], long int n)
{
long int i, j, min;
for (i = 0; i < n - 1; i++) {
// Find the minimum element in unsorted array
min = i;
for (j = i + 1; j < n; j++)
if (arr[j] < arr[min])
min = j;
// Swap the found minimum element
// with the first element
swap(&arr[min], &arr[i]);
}
}
// Driver code
int main()
{
long int n = 5000;
int iteration = 0;
// Arrays to store time duration
// of sorting algorithms
double time[10];
printf("A_size, Selection\n");
// Performs 10 iterations
while (iteration++ < 10) {
long int a[n];
// generating n random numbers
// storing them in array a
for (int i = 0; i < n; i++) {
long int num = rand() % n + 1;
a[i] = num;
}
// using clock_t to store time
clock_t start, end;
// Selection sort
start = clock();
selectionSort(a, n);
end = clock();
time[iteration] = ((double)(end - start));
// type conversion to long int
// for plotting graph with integer values
printf("%li, %li\n",
n, (long int)time[iteration]);
// increases the size of array by 500
n += 500;
}
return 0;
} 