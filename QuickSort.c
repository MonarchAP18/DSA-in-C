#include <stdio.h>

void Display(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int Division(int Arr[], int Lower, int HigherNum)
{
    int PIVOT = Arr[Lower];
    int i = Lower + 1;
    int j = HigherNum;
    int temp;

    do
    {
        while (Arr[i] <= PIVOT)
        {
            i++;
        }

        while (Arr[j] > PIVOT)
        {
            j--;
        }

        if (i < j)
        {
            temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
        }
    } while (i < j);

    
    temp = Arr[Lower];
    Arr[Lower] = Arr[j];
    Arr[j] = temp;
    return j;
}

void quickSort(int Arr[], int Lower, int HigherNum)
{
    int DivisionIndx; 

    if (Lower < HigherNum)
    {
        DivisionIndx = Division(Arr, Lower, HigherNum); 
        quickSort(Arr, Lower, DivisionIndx - 1);   
        quickSort(Arr, DivisionIndx + 1, HigherNum); 
    }
}

int main()
{
    
    int Arr[] = {23, 45, 67, 89, 12, 34, 91, 56, 78};
    
    int n =9;
    
    quickSort(Arr, 0, n - 1);
    Display(Arr, n);
    return 0;
}
