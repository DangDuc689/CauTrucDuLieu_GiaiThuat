#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *pNext;
} NODE;

typedef struct list
{
    NODE *pHead;
    NODE *pTail;
} LIST;

void Init(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* CreateNode(int x)
{
    NODE* p;
    p = new NODE;
    if (p == NULL)
    {
        printf("Khong cap phat duoc.");
        exit(0);
    }
    p->key = x;
    p->pNext = NULL;
    return p;
}

void InsertHead(LIST &l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void InsertTail(LIST &l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void InputList(LIST &l)
{
    int x; NODE* p;
    Init(l);
    while (1)
    {
        printf("Moi nhap x=");
        scanf("%d", &x);
        if (x == 0) break;
        p = CreateNode(x);
        InsertHead(l, p);
    }
}

void OutputList(LIST l)
{
    for (NODE* i = l.pHead; i != NULL; i = i->pNext)
        printf("%d->", i->key);
}

int TimViTriMin(int a[], int n)
{
    int vtmin = 0;
    for (int i = 1; i < n; i++)
        if (a[vtmin] > a[i])
            vtmin = i;
    return vtmin;
}

NODE* TimNodeMin(LIST l)
{
    NODE* nodemin = l.pHead;
    for (NODE* i = l.pHead->pNext; i != NULL; i = i->pNext)
        if (nodemin->key > i->key)
            nodemin = i;
    return nodemin;
}

int TongDS(LIST l)
{
    int S = 0;
    for (NODE* i = l.pHead; i != NULL; i = i->pNext)
        S += i->key;
    return S;
}

NODE* TimNodeGiaTriChan(LIST l)
{
    for(NODE* i=l.pHead; i!=NULL; i=i->pNext)
        if(i->key%2==0)
            return i;
    return NULL;
}

void InterchangeSort(LIST &l)
{
    for(NODE *i=l.pHead; i!=l.pTail; i=i->pNext)
        for(NODE* j=i->pNext; j!=NULL; j=j->pNext)
            if(i->key > j->key)
            {
                int t = i->key;
                i->key = j->key;
                j->key = t;
            }
}

int main()
{
    LIST l;
    printf("\nMoi nhap DSLK don:\n");
    InputList(l);
    printf("\nDSLK don sau khi nhap:\n");
    OutputList(l);
    /*NODE* i = TimNodeMin(L);
    printf("\nGia tri node min = %d", i->key);
    i=TimNodeGiaTriChan(L);
    if(i==NULL) printf("\nDS khong co chan.");
    else printf("\nNode co gia tri chan: %d", i->key);*/
    InterchangeSort(l);
    printf("\nSap xep InterchangeSort: \n");
    OutputList(l);
    return 0;
}