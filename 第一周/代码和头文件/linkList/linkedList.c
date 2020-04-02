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
	L = (LinkedList*)malloc(sizeof(LinkedList)); //头结点申请储存空间 
	if(!(*L)) return ERROR; 
	(*L)->next = NULL;        //初始化 
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
	}                 //从L起不停往后free直到尾结点NULL  
	*L=NULL;          //头结点销毁
	printf("链表已销毁"); 
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
	if (!p) printf("p为尾结点，不可做插入\n");             //p为尾结点 
	q=(LNode*)malloc(sizeof(LNode));  //为插入节点q申请存储空间 
	q->next=p->next;              //将原本位于p后的值赋予q后 
	p->next=q;                    //将p后指向的值等于q 
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
	if (!p && !p->next) return ERROR;      //考虑p和p->next会不会是尾结点？(排除
	q = p->next;                           //此时q=所要删的结点
	e = q->data;                           //assign its value to e
	p->next = q->next;                     //p的下一个结点为所要删的结点的下一个
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
	}                  //p从头结点开始访问链表
}
void vist(ElemType e)  //遍历输出 
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
	p=L->next;      //从头结点开始搜索 
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
	if ((*L)->next == NULL)  return ERROR;  //空链表情况 
	LNode* newL = NULL;  //新链表头结点
	LNode* p;          //过渡值 
	while (L != NULL) {         //非空链表情况 
		p = L;
		L = (*L)->next;
		newL = p;
	}
	return SUCCESS;
}                        
//假设头结点1->结点2->3->NULL    p        L        newL
//                                        1        NULL
//								 1		  2        1
//								 2        3        2
//                               3       NULL      3
//走完一遍循环 再return new->next  

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
	pfast=pslow=L;                     //同时同起点 
	while(L!=NULL){
		if(!pfast||!(pfast->next)){
			return 0;
		}                              //空链表或者只有一个节点 
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
	}                               //得到整个链表节点数count 
	m=*L;
	int i;
	for(i=0;i<count/2;i++){
		m=m->next;
	}                              //得到链表中点数 
	return m;
}


//创建链表
// LinkedList ListCreatH(){
//	LNode *L;
//	LNode *p;
//	ElemType number;
//    Status InitList(L);                  //初始化 
//	do{
//		scanf("%d", &number);
//		if(number!=-1){
//	        p=(LNode*)malloc(sizeof(LNode));  //申请新结点存储空间 
//	        p->data=number;                   //赋值 
//	        p->next=L->next;                   
//	        L->next=p; 
//			printf("%d ", p->data);                       //进入下一个结点 
//	    }
//	}while(number!=-1);                       //输入链表数据时以-1作结 
//	return p;
//}
void ListCreatH(){
	LNode *L,*p;
	Status InitList(L);
	int n;
	printf("请输入结点数：");
	scanf("%d", &n);
	ElemType number[n];
	int i;
	printf("请输入链表数据：");
	for(i=0;i<n;i++){
		p=(LNode*)malloc(sizeof(LNode));
		scanf("%d", &number[i]);
		p->data=number[i];
		p->next=L->next;
		L->next=p;
		printf("%d ", number[i]);
	}
}
