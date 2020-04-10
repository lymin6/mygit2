#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef  struct Node
{
	char data;
	struct Node *next;
}Node, *StackPtr;

typedef  struct  Stack
{
	StackPtr top;
	int	count;
}Stack;

Status initStack(Stack *s);
Status isEmptyStack(Stack *s);
char getTopStack(Stack *s);
char pushStack(Stack *s,char data);
char popStack(Stack *s);
char Pri(char str);
int calculation(char data,int n1,int n2);

#endif
