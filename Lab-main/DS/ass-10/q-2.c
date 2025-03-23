#include<stdio.h>
int main(int argc, char const *argv[])
{
    int arr[] = {64,25,12,22,64};
    int size = (sizeof(arr)/sizeof(int));
    for(int i = 0; i < size; i++){
        int max = arr[0];
        int index = 0;
        for(int j = 0 ; j<size-i;j++){
            if(arr[j]>max){
                max = arr[j];
                index = j;
            }
        }
        int temp = arr[index];
        arr[index] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
