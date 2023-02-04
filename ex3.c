#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int num;
    struct _listnode *next;
}ListNode;

typedef struct _linkedlist{
    ListNode *head;
    int size;
}LinkedList;

typedef struct _queue{
    LinkedList II;
} Queue;

void printList(ListNode *head){
    ListNode *cur = head;
    if(cur == NULL) printf("Danh sach lien ket khong co phan tu nao");
    while(cur != NULL){
        printf("%d\n", cur->num);
        cur = cur->next;
    }
}

ListNode *findNode(ListNode *head, int i){
    ListNode *cur = head;
    if(head == NULL || (i<0)){
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }

    while(i>0){
        cur = cur->next;
        i = i-1;
        if(cur == NULL){
            printf("Phan tu tim kiem khong ton tai");
            return NULL;
        };
        
    }
    return cur;
}

void insertNode(ListNode **pHead, int index, int value){
    ListNode *cur, *newNode;

    if (*pHead == NULL || index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }

    else if ((cur = findNode(*pHead, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode; 
    }
    else printf("can not insert the new item at index %d!\n", index);
}

void removeNode(ListNode **ptrHead, int index){
    ListNode *cur, *pre;
    if(index == 0){
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur);
    }
    else{
        pre = findNode(*ptrHead, index-1);
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
}

void enqueue(Queue *q, int item){
    insertNode(&(q->II.head), q->II.size, item);
    q->II.size = q->II.size + 1;
}

int dequeue(Queue *q){
    int item;
    if(q->II.head != NULL){
        item = q->II.head->num;
        removeNode(&(q->II.head),0);
        q->II.size = q->II.size - 1;
        return item;
    }
    else{
        printf("Hang doi rong");
        return 0;
    }
};

int peek(Queue *q){
    if(q->II.head != NULL) 
        return q->II.head->num;
    else{
        printf("Hang doi rong");
        return 0;
    }
};

int isEmptyQueue(Queue *q){
    if(q->II.size == 0) return 1;
    return 0;
};

int main(){
    Queue *q = malloc(sizeof(Queue));
    q->II.size = 0;
    q->II.head = NULL;
    printList(q->II.head);
    printf("\n");
    enqueue(q,20);
    enqueue(q,10);
    enqueue(q,30);
    dequeue(q);
    printf("%d \n",peek(q));
    if(isEmptyQueue){
        printf("Hang doi khong rong");
    }
    return 0;
}