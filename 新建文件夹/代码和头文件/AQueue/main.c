#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
int main()
{
	AQueue *Q;
	printf("序号--操作\n1-----入队\n2-----判断队列是否空\n3-----判断队列是否满\n4-----出队\n5-----确定队列的长度\n");
	printf("6-----查看队头元素\n7-----遍历队列\n8-----清空队列\n9-----销毁队列\n");
	int n=0,t;
	void *e;
	InitAQueue(Q);
	do{
		printf("请输入所要进行的操作的序号:");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("请输入要入队的数据类型的序号：1.整型；2.浮点型；3.字符:");
	            scanf("%d", &t);
	            Enswitch(&Q ,&t);
				break;
			case 2:
				IsEmptyAQueue(&Q);
				break;
			case 3:
				IsFullAQueue(&Q);
				break;
			case 4:
				DeAQueue(&Q);
				break;
			case 5:
				LengthAQueue(&Q);                  //???
				break;
			case 6:
				GetHeadAQueue(&Q, e);
				break;
            case 7:
            	TraverseAQueue(&Q, (e, Q->datatype));           //???
            	break;
            case 8:
            	ClearAQueue(&Q);
            	break;
            case 9:
            	DestoryAQueue(&Q);                      //???
            	break;
		}				
	}while(n!=9);
	
	system("pause");
	return 0;
}
