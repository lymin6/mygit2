#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
int main()
{
	AQueue *Q;
	printf("���--����\n1-----���\n2-----�ж϶����Ƿ��\n3-----�ж϶����Ƿ���\n4-----����\n5-----ȷ�����еĳ���\n");
	printf("6-----�鿴��ͷԪ��\n7-----��������\n8-----��ն���\n9-----���ٶ���\n");
	int n=0,t;
	void *e;
	InitAQueue(Q);
	do{
		printf("��������Ҫ���еĲ��������:");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("������Ҫ��ӵ��������͵���ţ�1.���ͣ�2.�����ͣ�3.�ַ�:");
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
