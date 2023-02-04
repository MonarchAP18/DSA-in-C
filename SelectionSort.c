#include<stdio.h>

int main(){
    
    int Array[] = {3, 5, 2, 18, 6, 21, 12, 16};
    int N = 8;
    
    SelectionSorting(Array, N);
    printArray(Array, N);

    return 0;
}


void printArray(int* Arr, int N){
    for (int i = 0; i < N; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void SelectionSorting(int *Arr, int N){
    int MinIndex, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < N-1; i++)
    {
        MinIndex = i;
        for (int j = i+1; j < N; j++)
        {
            if(Arr[j] < Arr[MinIndex]){
                MinIndex = j;
            }
        }
        // Swap A[i] and A[MinIndex]
        temp = Arr[i];
        Arr[i] = Arr[MinIndex];
        Arr[MinIndex] = temp;
    }
}

