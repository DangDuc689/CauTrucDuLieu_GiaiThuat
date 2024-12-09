#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    char lop[10];
    float gpa;
} SinhVien;

// node ket thuc bang NULL giong chuoi ky tu
typedef struct node{ // Cau truc cua node
    int Key;
    struct node* pNext;   // luu dia chi cua node tiep theo
} Node;

typedef struct {
    Node *pHead;
    Node *pTail;
}List;

void Init(List &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* CreateNote(int x){
    Node *p = (Node*) malloc(sizeof(Node));
    if (p == NULL){
        printf ("Khong cap phat duoc");
        exit(0);
    }
    p->Key = x;
    p->pNext = NULL;
    return p;
}

void InserHead(List &l, Node *p){
    if (l.pHead == NULL)
        l.pHead = l.pTail = p; // nếu danh sách rỗng thì p sẽ là nút đầu và cuối luôn
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void InserTail(List &l, Node *p){
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}


void Duyet(Node *pHead){ // giống như duyệt qua các phần từ trên mảng
    while (pHead != NULL){
        printf ("%d ", pHead->Key);
        pHead = pHead->pNext; // giống i++
    }
}

int Count(Node *Head){ // đếm các phần tử, như mảng
    int dem = 0;
    while (Head != NULL){
        dem++;
        Head = Head->pNext;
    }
    return dem;
}

int main(){
    List l;

    return 0;
}