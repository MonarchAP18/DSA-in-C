#include <stdio.h>
#include<string.h>
# define size 69


struct Stack{
 char stack[size];
 int top;
};

void initStack(struct Stack *s){
 (*s).top=-1;
 for(int i=0; i<size; i++){
  (*s).stack[i]='0';
 }
}
void push(struct Stack *s, char item, int sz){
 if((*s).top>=sz-1){
  printf("\nStack Overflow");
 }else{
  if(item==0){
   printf("\nerror");
  }else{
   (*s).top+=1;
   (*s).stack[(*s).top]=item;
  }
 }
}
char pop(struct Stack *s){
 if((*s).top==-1){
  printf("\nStack Underflow");
  return '0';
 }else{
  char item='0';
  item=(*s).stack[(*s).top];
  (*s).stack[(*s).top]=0;
  (*s).top-=1;
  return item;
 }
}

/*void revstr(char *s1, char *s2){
    struct Stack s;
    struct Stack *ptr;
    ptr=&s;
    initStack(ptr);
    int sz=sizeof(*s1)/1;
    for(int i=0; i<sz; i++){
        push(ptr,s1,sz);
    }
    for(int i=0; i<sz; i++){
        s2[i]=pop(ptr);
    }


}*/


int main(){
    struct Stack s;
    struct Stack *ptr;
    ptr=&s;
    initStack(ptr);
    char inp[size];
    int count=0;
    scanf("%s",&inp);
    //for(int i=0; i<sizeof(h)/1; i++){
       // scanf("%c",&inp[i]);
       // count++;
    //}
    
    char *p1,*p2;
    p1=inp;
    char out[size];
    p2=out;
    for(int i=0; i<strlen(inp); i++){
        push(ptr,inp[i],strlen(inp));
    }
    for(int i=0; i<strlen(inp); i++){
        printf("%c",pop(ptr));
    }


}

