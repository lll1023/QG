#include <stdio.h>
#include <malloc.h>
#include "DuLinkedList.h"
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    *L=(DuLinkedList)malloc(sizeof(DuLNode));
    if(!(*L)){
    	   printf("链表初始化失败\n");
	   return ERROR;
    } 
    (*L)->prior=NULL;
    (*L)->next=NULL;
      printf("链表初始化成功\n");
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList head=*L;
   if(head==NULL){
    	printf("该链表为空");
     return;
   }
    DuLinkedList freeNode=NULL;
   while(head){
	  freeNode=head;
      head=head->next;
      free(freeNode);
      printf("链表销毁成功");
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
    if(p==NULL){
    	   printf("节点p为空，插入失败");
        return ERROR;
    }else if(q==NULL){
    	  p->prior->next=NULL;
    }else{
      p->prior->next=q;
      q->prior=p->prior;  
      q->next=p;
      p->prior=q;  
    }
      printf("插入成功");
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
   if(p==NULL){
    	  printf("节点p为空，插入失败");
     return ERROR;
   }else if(q==NULL){
    	  p->next=NULL;
   }else{
	  if(p->next){
	        p->next->prior=q;
            q->next=p->next;
      }
         p->next=q;
         q->prior=p;
   }
      printf("插入成功");
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(p==NULL){
        printf("节点p为空");
     return ERROR;    
    }else if(p->next==NULL){
    	   printf("节点p的下一个节点为空");
       return ERROR;
    }else{
	     DuLinkedList deleteNode=p->next;
      if(deleteNode->next){
	        deleteNode->next->prior=p;
      }
         p->next=deleteNode->next;
      *e=deleteNode->data;
         free(deleteNode);
      return SUCCESS; 
    }
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
     if(L==NULL){
	    return;
    }
      DuLinkedList head=L->next;
      printf("链表元素有：");
    while(head){
	       visit(head->data);
           head=head->next;
    }

}

void visit(ElemType e){
	printf("%d\t",e);
}
