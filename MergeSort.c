#include <stdio.h>




void Displayy(int *Array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

void merge(int Array[], int mid, int LowElement, int Highest)
{
    int i;
    int j;
    int k;
    int B[100];
    i = LowElement;
    j = mid + 1;
    k = LowElement;

    while (i <= mid && j <= Highest)
    {
        if (Array[i] < Array[j])
        {
            B[k] = Array[i];
            i++;
            k++;
        }
        else
        {
            B[k] = Array[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = Array[i];
        k++;
        i++;
    }
    while (j <= Highest)
    {
        B[k] = Array[j];
        k++;
        j++;
    }
    for (int i = LowElement; i <= Highest; i++)
    {
        Array[i] = B[i];
    }
    
}

void Sorting(int Array[], int LowElement, int Highest){
    int mid; 
    if(LowElement<Highest){
        mid = (LowElement + Highest) /2;
        Sorting(Array, LowElement, mid);
        Sorting(Array, mid+1, Highest);
        merge(Array, mid, LowElement, Highest);
    }
}


int main()
{
    
    int Arr[] = {8, 2, 7, 17, 4, 15, 13};
    int n = 7;
    Sorting(Arr, 0, 6);
    Displayy(Arr, n);
    return 0;
}