#include <stdio.h>
#include <malloc.h>
#include "SqStack.h"
int main()
{
	SqStack *s;
	int sizes;
//	int n, i;
	printf("请输入栈元素的个数：");
	ElemType data;
    int n,i,*l;
    scanf("%d", &sizes);
    initStack(s,sizes);
    printf("序号-----操作\n1-------入栈\n2-------判断是否为空栈\n3-------得到栈顶元素\n4-------检测栈长度\n5-------出栈\n6-------清空栈\n7-------销毁栈（结束操作)\n");
    do{
    	printf("请输入所要进行的操作序号：");
        scanf("%d", &n);
        switch(n){
  	        case 1:
			    printf("请输入栈的元素：");
                for(i=0;i<sizes;i++){
	        	scanf("%d", &data);
		        pushStack(s,data);
	            }
	            break;
   	        case 2:
			    isEmptyStack(s);
   	            break;
   	         case 3:
	        	if(s->top!=-1){
	        		getTopStack(s,data);
	                printf("栈顶元素为%d\n ", data);
				}else{
					printf("为空栈\n");
				}
	            break;
	        case 4:
	        	stackLength(s,l);
	        	break;
	        case 5:if(s->top!=-1){
			            for(i=0;i<sizes;i++){
		                popStack(s,&data);
	                    }
				   }else{
	               	printf("为空栈\n");
				   }
	            break; 
	        case 6:
			    clearStack(s);
			    break;
	        case 7:
			    destroyStack(s);
	            break;
	    }
	}while(n!=7);
	return 0;
}
