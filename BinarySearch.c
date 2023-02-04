#include<stdio.h>
int binarySearch(int arr[], int Start, int Ends, int x)
{
    if (Ends >= Start) {
        int mid = Start + (Ends - Start) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, Start, mid - 1, x);// x is on Start side of sorted array
        return binarySearch(arr, mid + 1, Ends, x);//x on Ends side
    }
    return -1;
}
 
int main(void)
{
    int arr[] = { -5, -1, 3, 4, 7, 8, 9, 10, 15, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? printf("Element is not in array")
        : printf("Element is at index %d", result);
    return 0;
}