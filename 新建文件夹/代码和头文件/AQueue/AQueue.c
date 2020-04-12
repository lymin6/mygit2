#include "AQueue.h"
#include <malloc.h>
#include <stdlib.h>

void InitAQueue(AQueue *Q){
	Q=(AQueue *)malloc(sizeof(AQueue)*MAXQUEUE);
	Q->front=Q->rear=0;;
	
}

void DestoryAQueue(AQueue *Q){
	int i=0;
	for(;i<MAXQUEUE;i++){
		free(Q->data[i]);
	}
	Q->front=Q->rear=0; 
}

Status IsFullAQueue(const AQueue *Q){
	if((Q->rear+1)%MAXQUEUE==Q->front){
		printf("队列为满\n");
		return TRUE;
	}
		
	else{
		printf("队列不为满\n");
		return FALSE;
	}
		
}

Status IsEmptyAQueue(const AQueue *Q){
	if(Q->front==Q->rear){
		printf("队列为空\n");
		return TRUE;
	}else{
		printf("队列不为空\n");
		return FALSE;
	}
		 
}

Status GetHeadAQueue(AQueue *Q, void *e){
	if(Q->front==Q->rear){
		printf("队列为空\n");
		return FALSE;
	}else{
		memcpy(Q->data[Q->front],e,sizeof(Q)/MAXQUEUE);
		return TRUE;
	}
	
}

int LengthAQueue(AQueue *Q){
	size_t length;
	length=(Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
//	if(Q->front>Q->rear)
//		length=Q->rear-Q->front+MAXQUEUE;
//	else
//	    length=Q->rear-Q->front;
	    printf("%d\n", length);
//    return length;
//	length=(Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
}

Status EnAQueue(AQueue *Q, void *data){
	if((Q->rear+1)%MAXQUEUE==Q->front)
		return FALSE;
	else{
	    memcpy(Q->data[Q->rear],data,sizeof(Q)/MAXQUEUE);	
		Q->rear=(Q->rear+1)%MAXQUEUE;
		return TRUE;
	} 
}

Status DeAQueue(AQueue *Q){
	if(Q->front==Q->rear)
//		printf("队列为空，无元素可出队\n");
		return FALSE;
    else{
		Q->front=(Q->front+1)%MAXQUEUE;
		return TRUE;
	}
}

void ClearAQueue(AQueue *Q){
	Q->front=0;
	Q->rear=0;
	return TRUE;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int type)){
	InitAQueue(Q);
	if(Q->front==Q->rear){
		return FALSE;
	}else{
		int i;
		i=Q->front;
		while(i<(MAXQUEUE-Q->front+Q->rear)%MAXQUEUE){
			foo(Q->data[Q->front+i],Q->datatype[Q->front+i]);
			i=(i+1)%MAXQUEUE;
		}
		return TRUE;
	}
}

void APrint(void *q, int type){
	if (type == 1)
		printf("%d", *(int*)q);
	if (type == 2)
		printf("%lf", *(double*)q);
	if (type == 3)
		printf("%c", *(char*)q);
	printf("-<");
}

Status Enswitch(AQueue *Q,int *t){
	printf("请输入要入队的元素：");
//    switch(*t)
//	{
//	    case1:{
//	        int e;
//    	    scanf("%d", &e);
//            Q->datatype[Q->rear]=t;
//            EnAQueue(Q, &e);
//			break;
//		}
//        case 2:{
//        	double e;
//    	scanf("%.2lf", &e);
//    	Q->datatype[Q->rear]=t;
//    	EnAQueue(Q, &e);
//			break;
//		}
//		case 3:{
//			char e;
//        scanf("%c", &e);
//        Q->datatype[Q->rear]=t;
//        EnAQueue(Q, &e);
//			break;
//		}
//					}    
       if(t=1){
        int e;
    	scanf("%d", &e);
        Q->datatype[Q->rear]=t;
        EnAQueue(Q, &e);
		}
       if(t=2){
    	double e;
    	scanf("%lf", &e);
    	Q->datatype[Q->rear]=t;
    	EnAQueue(Q, &e);
    	}
        if(t=3){
   	    char e;
        scanf("%c", &e);
        Q->datatype[Q->rear]=t;
        EnAQueue(Q, &e);
		}        
}
