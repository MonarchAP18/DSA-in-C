#include<stdio.h>
int main()
{
    int arr[10]={1, 34, 20, 15, 10, 55, 131, 33, 87, 65};
    int n=sizeof(arr) / sizeof(arr[0]);
    int x=55;
    int a,i=0;
    for(i;i<n;i++){
        if(arr[i]==x){
            a=1;
            break;
        }else{
            a=0;
        }
    } 
    if(a==1)
        printf("Element found at index %d",i);
    else
        printf("Element not found");
  
    return 0;
}