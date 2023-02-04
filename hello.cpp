#include <iostream>
using namespace std;

typedef struct _listnode{
    int num;
    _listnode *next;
}ListNode;

ListNode *findNode(ListNode *head, int i){
    ListNode *cur = head;
    if(head == NULL || (i<0)){
        cout<<"Danh sach lien ket rong hoac phan tu tim kiem khong ton tai";
        return NULL;
    }
    while(i>0){
        cur = cur->next;
        i = i-1;
        if(cur == NULL){
            cout<<"Phan tu tim kiem khong ton tai";
            return NULL;
        };
        
    }
    return cur;
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
int main(){

    return 0;
}