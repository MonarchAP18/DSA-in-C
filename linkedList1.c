#include<stdio.h>  
#include<stdlib.h>  
struct Nodess   
{  
    int Data;  
    struct Nodess *next;   
};  
struct Nodess *head;  
  
void firstinsert ();   
void insertAtLast ();  
void randominsert();  
void DeleteElement(); 
void PrintList(); 
 
void main ()  
{  
    int c =0;  
    while(c!= 6)   
    {  
        
        printf("\n1.Insert Your Element in begining");
        printf("\n2.Insert the Element at last.");
        printf("\n3.Insert element at any random location");
        printf("\n4.Delete element from Beginning.");
        printf("\n5.Print the Complete List\n");

        printf("\nEnter your Your Prefered Operation?\n");         
        scanf("\n%d",&c);  
        switch(c)  
        {  
            case 1:  
            firstinsert();      
            break;  
            case 2:  
            insertAtLast();         
            break;  
            case 3:  
            randominsert();       
            break;  
            case 4:  
            DeleteElement();       
            break;
            case 5:
            PrintList();
            break;
            case 6:  
            exit(0);  
            break;
            
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void firstinsert()  
{  
    struct Nodess *pointer;  
    int item;  
    pointer = (struct Nodess *) malloc(sizeof(struct Nodess *));  
    if(pointer == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        pointer->Data = item;  
        pointer->next = head;  
        head = pointer;  
        printf("\nNodess inserted");  
    }  
      
}  

void DeleteElement()  
{  
    struct Nodess *pointer;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        pointer = head;  
        head = pointer->next;  
        free(pointer);  
        printf("\nNodess deleted from the begining ...\n");  
    }  
}  

void PrintList()  
{  
    struct Nodess *pointer;  
    pointer = head;  
    //printf("Enter how many elements to print"); 
    if(pointer == NULL)  
    {  
        printf("Nothing will be  print");  
    }  
    else  
    {  
        printf("\nprinting values \n");   
        while (pointer!=NULL)  
        {  
            printf("\n%d",pointer->Data);  
            pointer = pointer -> next;  
        }  
    }  
}   
void insertAtLast()  
{  
    struct Nodess *pointer,*temp;  
    int item;     
    pointer = (struct Nodess*)malloc(sizeof(struct Nodess));      
    if(pointer == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        pointer->Data = item;  
        if(head == NULL)  
        {  
            pointer -> next = NULL;  
            head = pointer;  
            printf("\nNodess inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = pointer;  
            pointer->next = NULL;  
            printf("\nNodess inserted");  
          
        }  
    }  
}  
void randominsert()  
{  
    int i,loc,item;   
    struct Nodess *pointer, *temp;  
    pointer = (struct Nodess *) malloc (sizeof(struct Nodess));  
    if(pointer == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&item);  
        pointer->Data = item;  
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        pointer ->next = temp ->next;   
        temp ->next = pointer;   
        printf("\nNodess inserted");  
    }  
}  

     
  