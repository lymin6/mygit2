#include <stdio.h>
#include <malloc.h>
#include "SqStack.h"
int main()
{
	SqStack *s;
	int sizes;
//	int n, i;
	printf("������ջԪ�صĸ�����");
	ElemType data;
    int n,i,*l;
    scanf("%d", &sizes);
    initStack(s,sizes);
    printf("���-----����\n1-------��ջ\n2-------�ж��Ƿ�Ϊ��ջ\n3-------�õ�ջ��Ԫ��\n4-------���ջ����\n5-------��ջ\n6-------���ջ\n7-------����ջ����������)\n");
    do{
    	printf("��������Ҫ���еĲ�����ţ�");
        scanf("%d", &n);
        switch(n){
  	        case 1:
			    printf("������ջ��Ԫ�أ�");
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
	                printf("ջ��Ԫ��Ϊ%d\n ", data);
				}else{
					printf("Ϊ��ջ\n");
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
	               	printf("Ϊ��ջ\n");
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
