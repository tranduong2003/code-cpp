#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct _listnode{
    int num;
    struct _listnode *next;
}ListNode;
typedef struct _linkedlist{
    ListNode *head;
    int size;
}LinkedList;
typedef struct _queue{
    LinkedList ll;
}Queue;
void printList(ListNode *head){
    ListNode *cur=head;
    if(cur==NULL){
        printf("Danh sach lien ket khong co phan tu nao");
        return;
    }
    while(cur!=NULL){
        printf("%d\n", cur->num);
        cur=cur->next;
    }
}
ListNode *findNode(ListNode *head, int i){
    ListNode *cur=head;
    if(head==NULL||i<0){
        printf("Danh sach lien ket khong ton tai");
        return NULL;
    }
    while(i>0){
        cur=cur->next;
        i--;
        if(cur==NULL){
            printf("Danh sach lien ket rong hoac khong co phan tu nao");
            return NULL;
        }
    }
    return cur;
}
void insertNode(ListNode **pHead, int index, int value){
    ListNode *cur, *newNode;
    if(*pHead==NULL||index==0){
        newNode=malloc(sizeof(ListNode));
        newNode->num=value;
        newNode->next=*pHead;
        *pHead=newNode;
    }
    else if ((cur = findNode(*pHead, index-1)) != NULL){
        newNode=malloc(sizeof(ListNode));
        newNode->num=value;
        newNode->next=cur->next;
        cur->next=newNode;
    }else printf("can not insert the new item at index %d\n", index);
}
void removeNode(ListNode **ptrHead, int index){
    ListNode *cur, *pre;
    if(index==0){
        cur=*ptrHead;
        *ptrHead=cur->next;
        free(cur);
    }else{
        pre=malloc(sizeof(ListNode));
        cur=pre->next;
        pre->next=cur->next;
        free(cur);
    }
}
void enqueue(Queue *q, int item){
    insertNode(&(q->ll.head), q->ll.size,item);
    q->ll.size++;
}
int dequeue(Queue *q){
    int item;
    if(q->ll.head!=NULL){
        item=(q->ll.head)->num;
        removeNode(&(q->ll.head),0);
        q->ll.size--;
        return item;
    }else{
        printf("Hang doi rong");
        return 0;
    }
}
int isEmtyQueue(Queue *q){
    if(q->ll.size==0) return 1;
    return 0;
}
int peek(Queue *q){
    if(q->ll.head!=NULL){
        return (q->ll.head)->num;
    }else{
        printf("Hang doi rong");
        return 0;
    }
}
void readData(char *filename, int G[MAX][MAX], int *pn, int * psource){
    FILE *file=fopen(filename, "r");
    int i,j;
    if(file !=NULL){
        fscanf(file,"%d %d",pn,psource);
        for(int i=0;i<*pn;i++){
            for(int j=0;j<*psource;j++){
                fscanf(file,"%d", G[i][j]);
            }
        }
    }
    fclose(file);
}

void breadthFistSearch(int g[MAX][MAX], int n, int source){
    int visited[MAX];
    int i,cur;
    Queue *q=malloc(sizeof(Queue));
    q->ll.size=0;
    q->ll.head=NULL;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    cur=source;
    visited[cur]=1;
    enqueue(q,cur);
    while(!isEmptyQueue(q)){
        cur=dequeue(q);
        printf(", %d", cur);
        for(i=0;i<n;i++){
            if(g[cur][i]!=0 && visited[i] ==0){
                visited[i]=1;
                enqueue(q,i);
            }
        }
    }
}
void BFS_Path(int g[MAX][MAX], int n, int startN, int endN){
    int visisted[MAX];
    int p[MAX];
    int i,j,cur;
    Queue *q=malloc(sizeof(Queue));
    q->ll.size=0;
    q->ll.head=NULL;

    for(i=0;i<n;i++){
        visisted[i]=0;
    }
    cur=startN;
    visisted[cur]=1;
    enqueue(q,cur);
    while(!isEmptyQueue(q)){
        cur=dequeue(q);
        printf("%d", cur);
        for(i=0;i<n;i++){
            if(g[cur][i]!=0&& visisted[i]==0){
                visisted[i]=1;
                enqueue(q,i);
                if(i==endN){
                    printf("found the path!");
                    printf("\nPath=%d", i);
                    j=i;
                    do{
                        j=p[j];
                        printf("<-%d",j);
                    }while(j!=startN);
                    return;
                }
            }
        }
    }
}

int main(void){
    int G[MAX][MAX],n,source;
    readData("data.txt", G ,&n,&source);
    breadthFistSearch(G,0,source);
    printf("\n");
    BFS_Path(G,n,source,2);
    return 0;
}