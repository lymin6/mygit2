#include "LinkStack.h"
#include <stdio.h>
#include<stdlib.h>
//typedef enum Status 
//{
//    ERROR = 0, 
//	SUCCESS = 1
//} Status;
//
//typedef int ElemType;
//
//typedef  struct StackNode
//{
//	ElemType data;
//	struct StackNode *next;
//}StackNode, *LinkStackPtr;    //结点（数据  指针） 
//
//typedef  struct  LinkStack
//{
//	LinkStackPtr top;        //栈顶 
//	int	count;               //结点数？ 
//}LinkStack;              


Status initLStack(LinkStack *s){
	s->top=NULL;
	s->count=0; 
	return 1;
}


Status isEmptyLStack(LinkStack *s){
	if(s->top==NULL){
		printf("为空栈\n");      //头指针指向空 
		return 1;
	}else{
		printf("不为空栈\n");
		return 0;
	}
}

Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top==NULL){
		printf("为空栈\n");
	} else{
		e=s->top->data;            //e等于栈顶元素 
		printf("栈顶元素为%d\n", e);
	}
}

Status clearLStack(LinkStack *s){
	LinkStackPtr p;
	while(s->top!=NULL){
		p=s->top;             //p指向栈顶 
	    s->top=s->top->next;    //向下 
	    s->count--;           
	    free(p);
	}

}

Status destroyLStack(LinkStack *s){
	clearLStack(s);
	free(s);
}

Status LStackLength(LinkStack *s,int *length){
//	LinkStackPtr p=s->top;
//	length=0;
//	while(s->top!=NULL){
//		p=p->next;
//		length++;
//	}
    length=s->count;
    printf("%d\n", length);
}



Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p;
	p=(LinkStackPtr*)malloc(sizeof(LinkStackPtr));
	p->data=data;
	p->next=s->top;      //新结点插入栈顶 
	s->top=p;    
	s->count++;         
	printf("%d已入栈\n", p->data);
}

Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
	p=s->top;
	data=p->data;
	s->top=p->next;
	s->count--;
	free(p);
	printf("%d出栈成功\n", data);
}
