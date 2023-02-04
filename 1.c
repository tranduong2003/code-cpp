#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int num;
    struct _listnode *next;
} ListNode;


void printList(ListNode *head){
    ListNode *cur = head;
    if(cur == NULL) printf("Danh sach lien ket khong co phan tu nao");
    while(cur != NULL){
        printf("%d\n",cur->num);
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
        cur = cur->next; i--;
        if(cur == NULL){
            printf("Phan tu tim kiem khong ton tai\n");
            return NULL;
        }
    }
    return cur;
}

void insertNode(ListNode **pHead, int index, int value){
    ListNode *cur, *newNode;
    if(*pHead == NULL || index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }
    else if((cur = findNode(*pHead,index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else printf("cannot insert the new item at index %d\n", index);
}
int main(){
    ListNode *node0, *node1, *head;
    node0 = malloc(sizeof(ListNode));
    node1 = malloc(sizeof(ListNode));
    node0->num = 20;
    node1->num = 30;
    node0->next = node1;
    node1->next = NULL;
    head = node0;
    printList(head);

    int index, value;
    printf("Nhap vi tri muon them vao: ");
    scanf("%d", &index);
    printf("Nhap gia tri muon them vao: ");
    scanf("%d", &value);
    insertNode(&head, index, value);
    printList(head);
    
    int vitri;
    printf("Nhap vao vi tri can tim: ");
    scanf("%d", &vitri);
    ListNode *new = findNode(head, vitri);
    printf("%d\n", new->num);
    
    
    return 0;
}