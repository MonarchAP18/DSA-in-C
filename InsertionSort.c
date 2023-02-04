// C program for insertion sort
#include <math.h>
#include <stdio.h>

//Driver cod3
int main()
{
	int Array[] = {34,12,45,78,56,91,23,67,89};
	int N = sizeof(Array) / sizeof(Array[0]);

	insertionSort(Array, N);
	Display(Array, N);

	return 0;
}

//Insertion sort code
void insertionSort(int Array[], int N)
{
    //declaring the variables
	int i;
    int  key;
    int  j;
	for (i = 1; i < N; i++) {
		key = Array[i];
		j = i - 1;

        //checking for necesary conditions to swap.
		while (j >= 0 && Array[j] > key) {
			Array[j + 1] = Array[j];
			j = j - 1;
		}
		Array[j + 1] = key;
	}
}
//printing Array
void Display(int Array[], int N)
{

	int i;
	for (i = 0; i < N; i++)
		printf("%d ", Array[i]);
}