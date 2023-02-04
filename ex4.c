#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    char item;
    struct _btnode *left;
    struct _btnode *right;
}BTNode;

void TreeTraversal2(BTNode *cur){
    if(cur == NULL) return;
    printf("%c",cur->item);
    TreeTraversal2(cur->left);
    TreeTraversal2(cur->right);
}

int main(){
    BTNode *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9, *head;
    node1 = malloc(sizeof(BTNode)); node2 = malloc(sizeof(BTNode));
    node3 = malloc(sizeof(BTNode)); node4 = malloc(sizeof(BTNode));
    node5 = malloc(sizeof(BTNode)); node6 = malloc(sizeof(BTNode));
    node7 = malloc(sizeof(BTNode)); node8 = malloc(sizeof(BTNode));
    node9 = malloc(sizeof(BTNode));

    node1->item = 'E', node2->item = 'B', node3->item = 'A', node4->item = 'C';
    node5->item = 'D', node6->item = 'G', node7->item = 'F', node8->item = 'I';
    node9->item = 'H';
    node1->left = node2, node1->right = node6;
    node2->left = node3, node2->right = node4;
    node3->right = NULL, node3->left = NULL;
    node4->right = node5, node4->left = NULL;
    node6->left = node7, node6->right = node8;
    node7->left = NULL, node7->right = NULL;
    node8->left = node9, node8->right = NULL;
    TreeTraversal2(node1);


    return 0;
}