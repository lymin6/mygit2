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
//}StackNode, *LinkStackPtr;    //��㣨����  ָ�룩 
//
//typedef  struct  LinkStack
//{
//	LinkStackPtr top;        //ջ�� 
//	int	count;               //������� 
//}LinkStack;              


Status initLStack(LinkStack *s){
	s->top=NULL;
	s->count=0; 
	return 1;
}


Status isEmptyLStack(LinkStack *s){
	if(s->top==NULL){
		printf("Ϊ��ջ\n");      //ͷָ��ָ��� 
		return 1;
	}else{
		printf("��Ϊ��ջ\n");
		return 0;
	}
}

Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top==NULL){
		printf("Ϊ��ջ\n");
	} else{
		e=s->top->data;            //e����ջ��Ԫ�� 
		printf("ջ��Ԫ��Ϊ%d\n", e);
	}
}

Status clearLStack(LinkStack *s){
	LinkStackPtr p;
	while(s->top!=NULL){
		p=s->top;             //pָ��ջ�� 
	    s->top=s->top->next;    //���� 
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
	p->next=s->top;      //�½�����ջ�� 
	s->top=p;    
	s->count++;         
	printf("%d����ջ\n", p->data);
}

Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
	p=s->top;
	data=p->data;
	s->top=p->next;
	s->count--;
	free(p);
	printf("%d��ջ�ɹ�\n", data);
}
