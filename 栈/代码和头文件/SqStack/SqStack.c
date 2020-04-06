#include "SqStack.h" 

Status initStack(SqStack *s,int sizes){
	s->size=sizes;           //栈空间的大小 
	s->elem=(ElemType*)malloc(sizeof(ElemType)*sizes);
	s->top=-1;
}


Status isEmptyStack(SqStack *s){
	if(s->top==-1){
		printf("是空栈\n");
		return 1;
	}
	else{
		printf("不是空栈\n");
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
	length=s->top+1;                //从0开始 
	printf("%d\n", length);
}



Status clearStack(SqStack *s){
	if(s->top==-1){
		printf("为空栈\n");
		return ERROR;
	}else{
		s->top=-1;
		printf("已清空");
		return SUCCESS; 
	}
}
 
Status destroyStack(SqStack *s){
	s->top=-1;
	s->size=0;
	free(s->elem);
	printf("销毁成功");
}


Status pushStack(SqStack *s,ElemType data){
	if(s->top<s->size){            //排除满栈情况 
		s->top++;                  // 向上增长 
		s->elem[s->top]=data;      //栈顶为data
        printf("%d已入栈\n", data);
//		data=s->elem[s->top];        //栈顶为data
		return SUCCESS;
	}else return ERROR;
}


Status popStack(SqStack *s,ElemType *data){
	while(s->top!=-1){        //非空栈 
		data=s->elem[s->top];      //data等于栈顶 
		s->top--;                //向下 
		printf("%d\n", data);
		return SUCCESS;
	}
}
