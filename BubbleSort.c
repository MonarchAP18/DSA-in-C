#include<stdio.h>
//#include<stdlib.h>

// We Start from writing a function to Swap two elements.
void Swapp(int* Xpos, int* Ypos){
    int temp = *Xpos;
    *Xpos= *Ypos;
    *Ypos= temp;
}
//Writing function to print the output.
void DisplayOutput(int Array[],int N){
    for(int i=0;i<N;i++){
        printf("%d ",Array[i]);
    }
}
// Writing the Bubblesort algorithm
void BubbleSort(int Array[], int N){
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            if(Array[j]>Array[j+1])
                Swapp(&Array[j],&Array[j+1]);
        }
    }
}

int main(){
    int Arr[]={23,56,89,78,34,12,45,67,91};
    int N= sizeof(Arr)/sizeof(Arr[0]);
    BubbleSort(Arr,N);
    printf("Array after Sorting\n");
    DisplayOutput(Arr,N);
    return 0;

}



