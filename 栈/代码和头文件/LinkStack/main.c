#include "LinkStack.h"
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
int main(){
	LinkStack *s;
	int i,count,n,l=0;
	initLStack(s);   //初始化 
	printf("请输入栈元素的个数：");
    scanf("%d", &count);
    ElemType *data;
    printf("序号-----操作\n1-------入栈\n2-------判断是否为空栈\n3-------得到栈顶元素\n4-------检测栈长度\n5-------出栈\n6-------清空栈\n7-------销毁栈（结束操作)\n");
    do{
    	printf("请输入所要进行的操作序号：");
    	scanf("%d", &n);
    	switch(n){
    		case 1:
    			printf("请输入入栈元素："); 
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
	               	printf("栈内没有元素\n");
				   }
	            break; 
	        case 6:
	        	clearLStack(s);
	            printf("已清空\n");
	        	break;
	        case 7:
	        	destroyLStack(s);
	        	printf("销毁成功\n");
	        	break;
	        case 4:
			    LStackLength(s,&l); 
			    break; 
        }
	}while(n!=7);
	return 0;
}
