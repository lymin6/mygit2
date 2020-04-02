#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	L = (LinkedList*)malloc(sizeof(LinkedList)); //ͷ������봢��ռ� 
	if(!(*L)) return ERROR; 
	(*L)->next = NULL;        //��ʼ�� 
	return SUCCESS;
}




/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList *p,q=*L;
	p=NULL;
	while (!p) { 
		p = q->next;     
		free(*p);
		p = q;            
	}                 //��L��ͣ����freeֱ��β���NULL  
	*L=NULL;          //ͷ�������
	printf("����������"); 
    return 0;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if (!p) printf("pΪβ��㣬����������\n");             //pΪβ��� 
	q=(LNode*)malloc(sizeof(LNode));  //Ϊ����ڵ�q����洢�ռ� 
	q->next=p->next;              //��ԭ��λ��p���ֵ����q�� 
	p->next=q;                    //��p��ָ���ֵ����q 
	return 0;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e 
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    LNode *q;
	if (!p && !p->next) return ERROR;      //����p��p->next�᲻����β��㣿(�ų�
	q = p->next;                           //��ʱq=��Ҫɾ�Ľ��
	e = q->data;                           //assign its value to e
	p->next = q->next;                     //p����һ�����Ϊ��Ҫɾ�Ľ�����һ��
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode *p;
	p=L;    
	while(p){
		visit(p->data);
		p=p->next;
	}                  //p��ͷ��㿪ʼ��������
}
void vist(ElemType e)  //������� 
{
	printf("%d ", e);
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode *p;
	p=L->next;      //��ͷ��㿪ʼ���� 
	while(!p){
		if(p->data==e) return SUCCESS;
		else p=p->next;
	} 
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if ((*L)->next == NULL)  return ERROR;  //��������� 
	LNode* newL = NULL;  //������ͷ���
	LNode* p;          //����ֵ 
	while (L != NULL) {         //�ǿ�������� 
		p = L;
		L = (*L)->next;
		newL = p;
	}
	return SUCCESS;
}                        
//����ͷ���1->���2->3->NULL    p        L        newL
//                                        1        NULL
//								 1		  2        1
//								 2        3        2
//                               3       NULL      3
//����һ��ѭ�� ��return new->next  

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(L->next==NULL)  return 0;
	LNode *pfast,*pslow;
	pfast=pslow=L;                     //ͬʱͬ��� 
	while(L!=NULL){
		if(!pfast||!(pfast->next)){
			return 0;
		}                              //���������ֻ��һ���ڵ� 
		else if(pfast==pslow||pfast->next==pslow){
			return 1;
		}
		else{
			pslow=pslow->next;
			pfast=pfast->next->next;
		}
	}

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L) 
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode *m=*L;
	int count;
	for(count=0;m==NULL;count++){
		m=m->next;
	}                               //�õ���������ڵ���count 
	m=*L;
	int i;
	for(i=0;i<count/2;i++){
		m=m->next;
	}                              //�õ������е��� 
	return m;
}


//��������
// LinkedList ListCreatH(){
//	LNode *L;
//	LNode *p;
//	ElemType number;
//    Status InitList(L);                  //��ʼ�� 
//	do{
//		scanf("%d", &number);
//		if(number!=-1){
//	        p=(LNode*)malloc(sizeof(LNode));  //�����½��洢�ռ� 
//	        p->data=number;                   //��ֵ 
//	        p->next=L->next;                   
//	        L->next=p; 
//			printf("%d ", p->data);                       //������һ����� 
//	    }
//	}while(number!=-1);                       //������������ʱ��-1���� 
//	return p;
//}
void ListCreatH(){
	LNode *L,*p;
	Status InitList(L);
	int n;
	printf("������������");
	scanf("%d", &n);
	ElemType number[n];
	int i;
	printf("�������������ݣ�");
	for(i=0;i<n;i++){
		p=(LNode*)malloc(sizeof(LNode));
		scanf("%d", &number[i]);
		p->data=number[i];
		p->next=L->next;
		L->next=p;
		printf("%d ", number[i]);
	}
}
