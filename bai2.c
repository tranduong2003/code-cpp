#include <stdio.h>
#include <stdlib.h>
typedef struct _listnode
{
    int num;
    struct _listnode *next;
} ListNode;

typedef struct list
{
    ListNode *pHead;
    ListNode *pTail;
} List;

int Khoitao(List *l)
{
    l->pHead = NULL;
    l->pTail = NULL;
};

ListNode *Khoi_tao_node(int x)
{
    ListNode *p = malloc(sizeof(ListNode));

    p->num = x;
    p->next = NULL;
    return p;
};

int Themvaodau(List *l, ListNode *p)
{
    if (l->pHead == NULL)
    {
        l->pHead = l->pTail = p;
    }else
    {
        p->next = l->pHead;
        l->pHead =p;      
    }
}

int Themvaocuoi(List *l, ListNode *p)
{
    if (l->pHead == NULL)
    {
        l->pHead = l->pTail = p;
    }else
    {
        l->pTail->next =p;
        l->pTail =p;      
    }
}
int xuat( List *l)
{
   ListNode *k = l->pHead;
    while ( k != NULL)
    {
         printf("%d ",k->num );
         k=k->next;
    }    
}
int main()
{
    List *a;
    Khoitao(a);
    int n;
    printf("Nhap N so luong phan tu trong danh sach: ");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
       int x;
       printf("Nhap gia tri cua so nguyen cua not thu %d: ",i);
       scanf("%d",&x);
       ListNode *p = Khoi_tao_node(x);
       Themvaocuoi(a,p);
    }
     printf("Danh sach lien ket: ");
     xuat(a);
}