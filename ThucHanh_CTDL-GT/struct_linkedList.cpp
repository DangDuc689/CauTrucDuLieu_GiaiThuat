#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int maSach;
    char tenSach[26];
    char tenTacGia[18];
    int namSX;
    int gia;
} Sach;

void NhapSach(Sach &x){
    printf ("\nNhap ma sach: ");
    scanf ("%d", &x.maSach);
    getchar();
    printf ("Nhap ten sach: ");
    gets(x.tenSach);
    printf ("Nhap ten tac gia sach: ");
    gets(x.tenTacGia);
    printf ("Nhap nam suat ban sach: ");
    scanf ("%d", &x.namSX);
    printf ("Nhap gia sach: ");
    scanf ("%d", &x.gia);
}

void XuatSach(Sach &x){
    printf ("%7d %26s %22s %10d %8d\n", x.maSach, x.tenSach, x.tenTacGia, x.namSX, x.gia);
}

typedef struct node {
    Sach data;
    struct node* pNext;
} Node;

typedef struct {
    Node* pHead;
    Node* pTail;
} List;

void Init(List &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

int isEmpty(Node* pHead) {
    return pHead == NULL;
}

Node* createNode(Sach x) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL){
        printf ("nut rong");
        exit(0);
    }    
    p->data = x;
    p->pNext = NULL;
    return p;
}

void inserTail(List &l, Node* p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void inputList(List &l) {
    Sach x;
    Node* p;
    Init(l);
    int sl;
    printf ("Nhap so luong sach: ");
    scanf ("%d", &sl);
    for (int i = 0; i < sl; i++){
		NhapSach(x);
        p = createNode(x);
        inserTail(l, p);
    }
}

void outputList(List l){
    printf("\n%7s %26s %22s %10s %8s\n", "Ma sach", "Ten sach", "Tac gia", "Nam SX", "Gia");
    for (Node* i = l.pHead; i != NULL; i = i->pNext)
        XuatSach(i->data);
}

void maSachTangDan(List &l){
    for (Node* i = l.pHead; i != l.pTail; i = i->pNext){
        for (Node* j = i->pNext; j != NULL; j = j->pNext){
            if (i->data.maSach > j->data.maSach){
                Sach t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}

void timSachTheoTenSach(List l){
    char s[26];
    int check = 0;
    printf ("Nhap ten sach can tim: ");
    getchar();
    gets(s);
    for (Node* i = l.pHead; i != NULL; i = i->pNext){
        if (strcmp(i->data.tenSach, s) == 0){
            XuatSach(i->data);
            check = 1;
        }
    }
    if (check == 0)
        printf ("Khong tim thay sach\n");
}

void lietKeNamSachTheoYeuCau(List l){
    int k, check = 0;
    printf ("\nNhap nam can tim: ");
    scanf ("%d", &k);
    for (Node* i = l.pHead; i != NULL; i = i->pNext){
        if (i->data.namSX >= k){
            XuatSach(i->data);
            check = 1;
        }
    }
    if (check == 0)
        printf ("khong tim thay nam\n");
}

void lietKeGiaSachTheoYeuCau(List l){
    int m, check = 0;
    printf ("\nNhap gia can tim: ");
    scanf ("%d", &m);
    for (Node* i = l.pHead; i != NULL; i = i->pNext){
        if (i->data.gia >= m){
            XuatSach(i->data);
            check = 1;
        }
    }
    if (check == 0)
        printf ("khong tim thay sach\n");
}

void XoaMaSach(List &l) {
    int ma;
    printf("\nNhap ma sach can xoa: ");
    scanf("%d", &ma);
    
    if (l.pHead == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    
    if (l.pHead->data.maSach == ma) {
        Node* temp = l.pHead;
        l.pHead = l.pHead->pNext;
        if (l.pHead == NULL) l.pTail = NULL;
            free(temp);
            printf("Da xoa sach co ma %d\n", ma);
            return;
    }
            
    Node* i = l.pHead;
    while (i->pNext != NULL && i->pNext->data.maSach != ma) {
        i = i->pNext;
    }
    
    if (i->pNext != NULL) {
        Node* temp = i->pNext;
        i->pNext = temp->pNext;
        if (i->pNext == NULL) l.pTail = i;
        free(temp);
        printf("Da xoa sach co ma %d\n", ma);
    } else {
        printf("Khong tim thay sach co ma %d\n", ma);
    }
}

int main() {
    Sach s;
    int chon;
    List l;
    do{
        printf ("\n0. Thoat chuong trinh\n" // cai nay viet printf binh thuong cung duoc
                "1. Nhap danh sach\n" 
                "2. Liet ke danh sach\n"
                "3. Sap xep thu tu tang dan theo ma\n"
                "4. Tim cuon sach dua tren ten sach\n"
                "5. Liet ke tat ca sach co nam theo yeu cau\n"
                "6. Liet ke tat ca sach co gia theo yeu cau\n"
                "7. Xoa sach theo ma sach\n"
                "\nNhap lua chon: ");
        scanf ("%d", &chon);
        switch(chon){
            case 0:
                printf ("Thoat chuong trinh\n");
                exit(0);
            case 1:
                inputList(l);
                break;
            case 2:
                outputList(l);
                break;
            case 3:
                maSachTangDan(l);
                outputList(l);
                break;
            case 4:
                timSachTheoTenSach(l);
                break;
            case 5:
                lietKeNamSachTheoYeuCau(l);
                break;
            case 6:
                lietKeGiaSachTheoYeuCau(l);
                break;
            case 7:
                XoaMaSach(l);
                break;
            default:
                printf ("vui long nhap so tu 0-7\n"); 
        }

    } while(chon != 0);

    
    return 0;
}
