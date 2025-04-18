#include<stdio.h>


    
// // A function to do counting sort of arr[] according to
// // the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	// output array
	int output[n];
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
void radixSort(int arr[],int n){
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>max){
            max = arr[i];
        }
    }
    for (int exp = 1;max/exp>0;exp*=10){
        countSort(arr,n,exp);
    }
}
int main(){
    int arr[] = {33, 45, 40, 25, 17, 24};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
    
