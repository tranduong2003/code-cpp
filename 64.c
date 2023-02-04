#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode {
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

void TreeTraversal_InOrder2(BTNode *cur) {
    if(cur==NULL) return;
    TreeTraversal_InOrder2(cur->left);
    printf("%c",cur->item);
    TreeTraversal_InOrder2(cur->right);
}

int countNode(BTNode*cur) {
    if (cur == NULL) return 0;
    int l = countNode(cur->left);
    int r = countNode(cur->right);
    return l+r+1; 
}

void findgrandchildren(BTNode *cur, int c, int k) {
    if (cur == NULL) return;
    if (c == k) {
        printf("%c ", cur->item);
        return;
    }
    findgrandchildren(cur->left, c+1,k);
    findgrandchildren(cur->right, c+1,k);
}

int TreeTraversal(BTNode *cur) {
    if (cur == NULL)
        return -1;
    int l = TreeTraversal(cur->left);
    int r = TreeTraversal(cur->right);
    int c = max(l, r) + 1;
    return c;
}

int main(){
    BTNode *btnodeA, *btnodeB, *btnodeC, *btnodeD, *btnodeE, *btnodeF, *btnodeG, *btnodeH, *btnodeI, *btnodeJ, *btnodeK, *btnodeL, *btnodeM;
    btnodeA = malloc(sizeof(BTNode));
    btnodeB = malloc(sizeof(BTNode));
    btnodeC = malloc(sizeof(BTNode));
    btnodeD = malloc(sizeof(BTNode));
    btnodeE = malloc(sizeof(BTNode));
    btnodeF = malloc(sizeof(BTNode));
    btnodeG = malloc(sizeof(BTNode));
    btnodeH = malloc(sizeof(BTNode));
    btnodeI = malloc(sizeof(BTNode));
    btnodeJ = malloc(sizeof(BTNode));
    btnodeK = malloc(sizeof(BTNode));
    btnodeL = malloc(sizeof(BTNode));
    btnodeM = malloc(sizeof(BTNode));

    btnodeA->item='A';
    btnodeB->item='B';
    btnodeC->item='C';
    btnodeD->item='D';
    btnodeE->item='E';
    btnodeF->item='F';
    btnodeG->item='G';
    btnodeH->item='H';
    btnodeI->item='I';
    btnodeJ->item='J';
    btnodeK->item='K';
    btnodeL->item='L';
    btnodeM->item='M';

    btnodeA->left=NULL;
    btnodeA->right=NULL;

    btnodeB->left=btnodeA;
    btnodeB->right=btnodeC;

    btnodeC->left=NULL;
    btnodeC->right=btnodeD;


    btnodeD->left=NULL;
    btnodeD->right=NULL;

    btnodeE->left=btnodeB;
    btnodeE->right=btnodeF;

    btnodeF->left=NULL;
    btnodeF->right=btnodeG;

    btnodeG->left=NULL;
    btnodeG->right=NULL;

    btnodeH->left=btnodeE;
    btnodeH->right=btnodeL;

    btnodeI->left=NULL;
    btnodeI->right=NULL;

    btnodeJ->left=btnodeI;
    btnodeJ->right=btnodeK;

    btnodeK->left=NULL;
    btnodeK->right=NULL;

    btnodeL->left=btnodeJ;
    btnodeL->right=btnodeM;

    btnodeM->left=NULL;
    btnodeM->right=NULL;    
    printf("%d \n", countNode(btnodeA));
    findgrandchildren(btnodeA,2,2);
    printf("\n%d ", TreeTraversal(btnodeA));
    return 0;
}