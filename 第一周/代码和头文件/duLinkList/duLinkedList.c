#include "../head/duLinkedList.h"
#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	L = (DuLinkedList *)malloc(sizeof(DuLinkedList ));
	if(!(*L)) return ERROR; 
	(*L)->prior=NULL;
	(*L)->next=NULL;                 //初始化 
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList *p,q=*L;
	p=NULL;
	while (p->next=L) { 
		p = q->next;     
		free(*p);
		p = q;            
	}                 //从L起不停往后free直到回到L  
	*L=NULL;          //头结点销毁
	printf("链表已销毁"); 
    return 0;
}

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(!(p->prior)) return ERROR;     //p是头结点时 
	else{
		q->prior=q->prior;
		p->prior->next=q;
		q->next=p;
		p->prior=q;
		return SUCCESS;
	}

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(!P) return ERROR;            //p是尾结点时
	else{
		p->next=q->next;
		p->next->prior=q;
		q->prior=p;
		p->next=q;
		return SUCCESS;
	} 

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(!p) return ERROR;         //p是尾结点时    
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return SUCCESS;

}


/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode *p;
	p=L->next;
	while(p){
		visit(p->data);
		p=p->next;
	}
	return 0;
}                          //选取一个方向遍历 next方向 
void (*visit)(ElemType e){
	printf("%d", e);
}
