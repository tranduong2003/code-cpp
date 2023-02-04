#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int num;
    struct _listnode *next;
}ListNode;

typedef struct _linkedlist{
    ListNode *head;
    int size;
} Linkedlist;

typedef struct _stack{
    Linkedlist II;
    int size;
} Stack;

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

void push(Stack *s, int item){
    insertNode(&(s->II.head),0,item);
    s->II.size ++;
}

int pop(Stack *s){
    int item;
    if(!isEmptyStack(s)){
        item = s->II.head->num;
        removeNode(&(s->II),0);
        (s->II).size --;
        return item;
    }
    else{
        printf("Ngan xep rong");
        return NULL;
    }
}

int peek(Stack *s){
    if(s->II.head != NULL){
        return s->II.head->num;
    }
    else{
        printf("Ngan xep rong");
        return NULL;
    }
}
int isEmptyStack(Stack *s){
    if((s->II).size == 0) return 1;
    return 0;
}

int main(){
    Stack *s = malloc(sizeof(Stack));
    s->II.size = 0;
    s->II.head = NULL;
    printList(s->II.head);
    printf("\n");
    push(s,10);
    push(s,20);
    push(s,30);
    pop(s);
    printf("%d \n",peek(s));
    if(isEmptyStack){
        printf("Ngan xep khong rong");
    }
    return 0;
}