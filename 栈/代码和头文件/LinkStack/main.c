#include "LinkStack.h"
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
int main(){
	LinkStack *s;
	int i,count,n,l=0;
	initLStack(s);   //��ʼ�� 
	printf("������ջԪ�صĸ�����");
    scanf("%d", &count);
    ElemType *data;
    printf("���-----����\n1-------��ջ\n2-------�ж��Ƿ�Ϊ��ջ\n3-------�õ�ջ��Ԫ��\n4-------���ջ����\n5-------��ջ\n6-------���ջ\n7-------����ջ����������)\n");
    do{
    	printf("��������Ҫ���еĲ�����ţ�");
    	scanf("%d", &n);
    	switch(n){
    		case 1:
    			printf("��������ջԪ�أ�"); 
			    for(i=0;i<count;i++){
    	        scanf("%d", &data);
	            pushLStack(s,data);
		}
		    break;
    		case 2:
			    isEmptyLStack(s);
			    break;
            case 3:
            	getTopLStack(s,&data);
            	break;
            case 5:
            	if(s->top!=NULL){
		                popLStack(s,&data);
				   }else{
	               	printf("ջ��û��Ԫ��\n");
				   }
	            break; 
	        case 6:
	        	clearLStack(s);
	            printf("�����\n");
	        	break;
	        case 7:
	        	destroyLStack(s);
	        	printf("���ٳɹ�\n");
	        	break;
	        case 4:
			    LStackLength(s,&l); 
			    break; 
        }
	}while(n!=7);
	return 0;
}
