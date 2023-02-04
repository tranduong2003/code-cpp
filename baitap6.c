#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode {
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void TreeTraversal_PreOrder(BTNode *cur) {
    if(cur==NULL) return;
    printf("%d ",cur->item);
    TreeTraversal_PreOrder(cur->left);
    TreeTraversal_PreOrder(cur->right);
}

void TreeTraversal_InOrder(BTNode *cur) {
    if(cur == NULL) return;
    TreeTraversal_InOrder(cur->left);
    printf("%d ",cur->item);
    TreeTraversal_InOrder(cur->right);
}

void TreeTraversal_PostOrder(BTNode *cur) {
    if(cur==NULL)
        return;
    TreeTraversal_PostOrder(cur->left);
    TreeTraversal_PostOrder(cur->right);
    printf("%d ",cur->item);
}

int main() {
    int item1 = 1, item2 = 2, item3 = 3;
    BTNode *btnode1, *btnode2, *btnode3;
    btnode1 = malloc(sizeof(BTNode));
    btnode2 = malloc(sizeof(BTNode));
    btnode3 = malloc(sizeof(BTNode));

    btnode1->item = item1;
    btnode2->item = item2;
    btnode3->item = item3;

    btnode2->left = NULL;
    btnode2->right = NULL;

    btnode3->left = NULL;
    btnode3->right = NULL;

    btnode1->left = btnode2  ;
    btnode1->right = btnode3 ;
    
    printf("Duyet cay theo thu tu truoc: ");
    TreeTraversal_PreOrder(btnode1);

    printf("\nDuyet cay theo thu tu giua: ");
    TreeTraversal_InOrder(btnode1);

    printf("\nDuyet cay theo thu tu sau: ");
    TreeTraversal_PostOrder(btnode1);
}