#include <stdio.h>
#include <stdlib.h>

struct sinhVien{
    char name[30];
    char lop[10];
    float gpa;
};

// node ket thuc bang NULL giong chuoi ky tu
struct Node{
    int Data;
    Node* Next;   // luu dia chi cua node tiep theo
};

Node* createNote(int x){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->Data = x;
    newNode->Next = NULL;
    return newNode;
};

void Duyet(Node *Head){ // giống như duyệt qua các phần từ trên mảng
    while (Head != NULL){
        printf ("%d ", Head->Data);
        Head = Head->Next; // giống i++
    }
}

int Count(Node *Head){ // đếm các phần tử, như mảng
    int dem = 0;
    while (Head != NULL){
        dem++;
        Head = Head->Next;
    }
    return dem;
}

int main(){


    return 0;
}