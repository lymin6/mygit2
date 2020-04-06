#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
    SUCCESS = 1
} Status;

typedef  struct Node
{
    int data;
    struct Node *next;
}Node, *StackPtr;

typedef  struct  Stack
{
    StackPtr top;
    int count;
}Stack;

Status initStack(Stack *s);
Status isEmptyStack(Stack *s);
int getTopStack(Stack *s);
int pushStack(Stack *s,int data);
int popStack(Stack *s,int data);
int Pri(char str);


#endif
