#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

Status initStack(Stack *s){
    s->top = (Node*)malloc(sizeof(Node));
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

char getTopStack(Stack *s){
	if(s->top!=NULL)
		return (s->top->data);
	}


char pushStack(Stack *s,char data){
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->data=data;
	p->next=s->top;      //新结点插入栈顶 
	s->top=p;    
	s->count++;         
}

char popStack(Stack *s){
	StackPtr p;
	char data;
	p=s->top;
	data=p->data;
	s->top=p->next;
	s->count--;
	free(p);
	return data;
}


int calculation(char data,int n1,int n2){
      int n3=0;
	    switch(data)	{   //比如说bc-不是c-b，而是b-c 
		    case '+':
		        n3=n2+n1;break;
		    case '-':
		        n3=n2-n1;break;
		    case '*':
		        n3=n2*n1;break;
		    case '/':
		    	n3=n2/n1;break;
			        }
	return n3;
}
