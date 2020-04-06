#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

Status initStack(Stack *s){
    s->top=NULL;
    s->count=0; 
}

Status isEmptyStack(Stack *s){
    if(s->top==NULL){     //头指针指向空 
        return 1;
    }else{
        return 0;
 }
}

int getTopStack(Stack *s){
    if(s->top!=NULL)
       return (s->top->data);
 }


int pushStack(Stack *s,int data){
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->next=s->top;      //新结点插入栈顶 
    s->top=p;    
    s->count++;         
}

int popStack(Stack *s,int data){
    StackPtr p;
    p=s->top;
    data=p->data;
    s->top=p->next;
    s->count--;
    free(p);

    return data;
}

int Pri(char str)
{
    switch(str)
    {
        case'(':
            return 3;
            break;
        case'*':
        case'/':
            return 2;
            break;
        case'+':
        case'-':
            return 1;
            break;
        default:
            return 0;
            break;
 }
}
