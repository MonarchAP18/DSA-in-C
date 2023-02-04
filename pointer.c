#include<stdio.h>
int main(){
    int X=5;
    int *ptr;
    ptr=&X;
    printf("%d",*ptr);
}


// int main(){
//     int X=10;
//     void *ptr=&X;
//     printf("%d",*(int*)ptr);
//     return 0;
// }