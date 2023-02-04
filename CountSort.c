 #include <stdio.h>

// void CountSort(int Array[],int N){
//     int i;
//     int b[N];

//     int Maximum = Array[0];
//     for(i=1;i<N;i++){
//         if(Array[i]>Maximum){
//             Maximum=Array[i];
//         }
//     }

//     int count[Maximum+1];

//     for(i=0;i<=Maximum;i++){
//         count[i]=0;
//     }

//     //Store the number of occurences for each element.
//     for(i=0;i<N;i++){
//         count[Array[i]]++;
//     }

//     for(i=1;i<Maximum;i++){
//         count[i]=count[i]+count[i-1];
//     }
//     for(i=N;i>0;i--){
//         b[--count[Array[i]]]=Array[i];
//     }
//     for(i=0;i<N;i++){
//         Array[i]=b[i];
//     }
// }

// int main()
// {
//     int N;
//     int i;
//     //printf("Enter Number of elements you want in Array");
//     //scanf("%n",)


//     int Array[]={2,4,1,2,7,4,2,6};

//     CountSort(Array,N);
//     printf("THE SORTED ARRAY\n");
//     for(i=0;i<N;i++){
//         printf("%d ",Array[i]);
//     }
//     return 0;
// }

void CountingSort(int array[],int n){
    int i;
    int Output[n];

    //find the largest element of the Array.
    int Max=array[0];
    for(i=1;i<n;i++){
        if(array[i]>Max)
            Max=array[i];
    }
        //making a count array to store number of occurences and initiallizing it with 0.
    int Count[Max+1];
    for(i=0;i<=Max;i++){
        Count[i]=0;
    }
        //Storing number of occurences of each element in the count Array.
    for(i=0;i<n;i++){
        Count[array[i]]++;

    }
    //Updating the count Array
    for(i=0;i<Max;i++){
        Count[i]=Count[i]+Count[i-1];
    }
    //Finding index of each element and place element.
    for(i=n-1;i>=0;i--){
        Output[--Count[array[i]]]=array[i];
    }

    for(i=0;i<n;i++){
        array[i]=Output[i];

    }
}

int main(){
    int n;
    int i;
    int Array[n];
    printf("Enter Number of element wanted in Array");
    scanf("%d",&n);

    
    printf("Enter elements of Array");
    for(i=0;i<n;i++){
        scanf("%d",&Array[i]);
    }
    printf("The Sorted Array:\n");
    for(i=0;i<n;i++){
        printf("%d",&Array[i]);
    }

    CountingSort(Array,n);
    printf("The Sorted Array\n");
    return 0;
}