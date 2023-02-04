// C code for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 300

void CountingSort(char Arr[])
{

char output[strlen(Arr)];

int CountTrack[RANGE + 1];
int  i;
memset(CountTrack, 0, sizeof(CountTrack));

for (i = 0; Arr[i]; ++i)
++CountTrack[Arr[i]];

for (i = 1; i <= RANGE; ++i)
CountTrack[i] += CountTrack[i - 1];

for (i = 0; Arr[i]; ++i) {
output[CountTrack[Arr[i]] - 1] = Arr[i];
--CountTrack[Arr[i]];
}

for (i = 0; Arr[i]; ++i)
Arr[i] = output[i];

}

int main(){

char Arr[] = "AkshayPadamwar";

CountingSort(Arr);

printf("Sorted array using counting sort: \n%s", Arr);
return 0;

}