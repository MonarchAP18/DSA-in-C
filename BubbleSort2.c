#include<stdio.h>
#include<stdlib.h>  

void DisplayArray(int* Arr,int n){
    for(int i=0;i<n;i++)
    {
        printf("%d",*Arr+i);
    }
    printf("\n");
}
void BUBBLE(int* Arr, int n){
    int temp;
    for (int i = 0; i <n-1; i++)
    {
        for(int j=0;j<n-i-1;i++){
            if(Arr[j]>Arr[j+1]){
                temp=Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j+1]=temp;
            }
        }
    }
    
    
}

int main()
{
    int *Arr;
    
    int n = 9;
    DisplayArray(*Arr,n); //printing the array before sorting
    BUBBLE(Arr,n);
    printf("Sort\n");
    DisplayArray(Arr,n); //printing array after sorting.
    return 0;
}
