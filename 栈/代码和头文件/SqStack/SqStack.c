#include "SqStack.h" 

Status initStack(SqStack *s,int sizes){
	s->size=sizes;           //ջ�ռ�Ĵ�С 
	s->elem=(ElemType*)malloc(sizeof(ElemType)*sizes);
	s->top=-1;
}


Status isEmptyStack(SqStack *s){
	if(s->top==-1){
		printf("�ǿ�ջ\n");
		return 1;
	}
	else{
		printf("���ǿ�ջ\n");
		return 0; 
	}
}


Status getTopStack(SqStack *s,ElemType *e){
	if(s->top==-1){
		*e=s->elem[s->top];
	    return SUCCESS; 
	}else{
		return ERROR;
	}
} 


Status stackLength(SqStack *s,int *length){
	length=s->top+1;                //��0��ʼ 
	printf("%d\n", length);
}



Status clearStack(SqStack *s){
	if(s->top==-1){
		printf("Ϊ��ջ\n");
		return ERROR;
	}else{
		s->top=-1;
		printf("�����");
		return SUCCESS; 
	}
}
 
Status destroyStack(SqStack *s){
	s->top=-1;
	s->size=0;
	free(s->elem);
	printf("���ٳɹ�");
}


Status pushStack(SqStack *s,ElemType data){
	if(s->top<s->size){            //�ų���ջ��� 
		s->top++;                  // �������� 
		s->elem[s->top]=data;      //ջ��Ϊdata
        printf("%d����ջ\n", data);
//		data=s->elem[s->top];        //ջ��Ϊdata
		return SUCCESS;
	}else return ERROR;
}


Status popStack(SqStack *s,ElemType *data){
	while(s->top!=-1){        //�ǿ�ջ 
		data=s->elem[s->top];      //data����ջ�� 
		s->top--;                //���� 
		printf("%d\n", data);
		return SUCCESS;
	}
}
