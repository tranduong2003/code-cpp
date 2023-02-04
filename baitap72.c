#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
} Node;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

Node *insert(Node *t, int x){
	if (t == NULL){
		Node *temp;
		temp->data =x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else{
		if (x < t->data){
			t->left = insert(t->left, x);
		} else{
			t->right = insert(t->right, x);
		}
	}
	
}


int treeLevel(Node *t){
	if (t == NULL) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

int checkAvl(Node *t){
	if (t == NULL) return 1;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return 0;
	return checkAvl(t->left) && checkAvl(t->right);
}

int main(){
	int n, temp;
	scanf("%d",&n);
	Node * t = NULL;
	for (int i = 0; i < n; i++){
		scanf("%d",&temp);
		t = insert(t, temp);
	}
	if(checkAvl(t)) printf("Dung");
    else printf("Sai");
	return 0;
}