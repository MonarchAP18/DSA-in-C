#include <stdio.h>
#include <stdlib.h>

int top_Operator = -1;
int top_operator = -1;

int Operen(char c){
    if (c>=97 && c<=122){
        return 1;
    }
    return 0;
}
int isOperatorEmpty(){
    if(top_operator == -1) return 1;
    else return 0;
}
void push_operator(char c, char stack[]){
    stack[++top_operator] = c;
}
char pop_operator(char stack[]){
    char p = stack[top_operator--];
    return p;
}
void display_operand(char stack[]){
    //printf("TOP-\n");
    for (int i = 0;i<=top_Operator;i++){
        printf("%c ", stack[i]);
    }
}
void push_operand(char c, char stack[]){
    stack[++top_Operator] = c;
}


int compare(char top, char ele){
    //returns 1 if both are equal
    //returns 2 if a>b
    //returns -1 if a<b
    
    char arr[] = {'+','-',',','*','/'};
    int a,b;
    for (int i=0;i<5;i++){
        if (arr[i] == top) a = i;
        if (arr[i] == ele) b = i;
    }

    if (abs(a-b) == 0 || abs(a-b) == 1) return 1;
    else{
        if (a>b) return 2;
        else return -1;
    }
}
int main(){
    
    char s[20];
    scanf("%s", s);
    int length = 0;
    int k = 0;
    while (*(s+k) != '\0'){
        length++;
        k++;
    }
    
    char Outpu[length];  //Outpuut stack
    char S[length]; //operator stack

    for (int i = 0; i<length; i++){
        char ele = *(s+i);
        if (Operen(ele) == 1){
            //printf("Operand found: %c\n", ele);
            push_operand(ele,Outpu);
        }
        else if (ele == '('){
            push_operator(ele,S);
        }
        else if (ele == ')'){
            unsigned char j = top_operator;
            while (S[j]!='('){
                char c = pop_operator(S);
                push_operand(c, Outpu);
                j--;
            }
            pop_operator(S); //for removing '('
        }
        else {
            while ((S[top_operator]!='(') && (isOperatorEmpty() != 1) && (compare(S[top_operator],ele) >= 1)){
                char p = pop_operator(S);
                push_operand(p,Outpu);
            } 
            push_operator(ele,S);
        }
    }
    while (top_operator != -1){
        char l = pop_operator(S);
        push_operand(l, Outpu);
    }
    display_operand(Outpu);
}