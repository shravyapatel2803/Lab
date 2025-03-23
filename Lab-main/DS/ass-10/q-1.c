#include<stdio.h>
int main(){
    int numb[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = (sizeof(numb)/sizeof(int));
    for(int i = 0;i<size;i++){
       for(int j=1;j<size-i;j++){
            if(numb[j-1]>numb[j]){
                int temp = numb[j-1];
                numb[j-1] = numb[j];
                numb[j]=temp;
            }
           }
        }
    for(int i = 0 ; i<size;i++){
        printf("%d ",numb[i]);
    }
}