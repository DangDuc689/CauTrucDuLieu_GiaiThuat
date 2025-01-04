#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    int key;
    struct tnode* pLeft;
    struct tnode* pRight;
} tNode;

typedef tNode* Tree;

void Init(Tree &t) {
    t = NULL;
}

tNode* CreateNode(int key) {
    tNode* p = (tNode*)malloc(sizeof(tNode));
    if (p != NULL) {
        p->key = key;
        p->pLeft = p->pRight = NULL;
    }
    return p;
}

void Insert(Tree &t, int key) {
    if (t == NULL) {
        t = CreateNode(key);
    } else {
        if (key < t->key) {
            Insert(t->pLeft, key);
        } else if (key > t->key) {
            Insert(t->pRight, key);
        }
    }
}

// duyệt cây: LNR, NLR, LRN
void DuyetLNR(Tree t) {  // tăng dần: LNR || giảm dần: RNL
    if (t != NULL) {
        DuyetLNR(t->pLeft);     // left
        printf("%d ", t->key); // Node
        DuyetLNR(t->pRight);    // right
    }
}

// void DuyetNLR(Tree t){
//     if (t != NULL){
//         printf ("%d ", t->key);
//         DuyetNLR(t->pLeft);
//         DuyetNLR(t->pRight);
//     }
// }

// void DuyetLRN(Tree t){
//     if (t != NULL){
//         DuyetLRN(t->pLeft);
//         DuyetLRN(t->pRight);
//         printf ("%d ", t->key);
//     }
// }

// void DuyetRNL(Tree t) { // node giam dan
//     if (t != NULL) {
//         DuyetRNL(t->pRight);
//         printf("%d ", t->key);
//         DuyetRNL(t->pLeft);
//     }
// }

// int KiemTraBST(Tree t, int min, int max) {
//     if (t == NULL) return 1;
//     if (t->key <= min || t->key >= max) return 0;
//     return KiemTraBST(t->pLeft, min, t->key) && KiemTraBST(t->pRight, t->key, max);
// }

// int LaBST(Tree t) {
//     return KiemTraBST(t, -1000000, 1000000);
// }

int TreeDayDu(Tree t) { // cây BST đầy đủ: chỉ có 0 hoặc 2 con (ko có tường hợp 1 con)
    if (t == NULL) return 1;
    if ((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL)) return 0;
    return TreeDayDu(t->pLeft) && TreeDayDu(t->pRight);
}

tNode* TimMin(tNode* t) { // TimMax: thay pLeft = pRight
    if (t != NULL) {
        while (t->pLeft != NULL) { 
            t = t->pLeft;
        }
    }
    return t;
}

// int TimMin(Tree t) {
//     if (t != NULL) {
//         while (t->pLeft != NULL) {
//             t = t->pLeft;
//         }
//     }
//     return t;
// }

int DemNode(Tree t) { // số node trong cây
    if (t == NULL) return 0;
    return 1 + DemNode(t->pLeft) + DemNode(t->pRight);
}

int DemLa(Tree t) { // số lá trong cây
    if (t == NULL) return 0;
    if (t->pLeft == NULL && t->pRight == NULL) return 1;
    return DemLa(t->pLeft) + DemLa(t->pRight);
}

int TongNode(Tree t) { // cộng các key của tree
    if (t == NULL) return 0;
    return t->key + TongNode(t->pLeft) + TongNode(t->pRight);
}

int ChieuCaoTree(Tree t) { // chiều cao
    if (t == NULL) return 0;
    int leftHeight = ChieuCaoTree(t->pLeft);
    int rightHeight = ChieuCaoTree(t->pRight);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int DemHaiCon(Tree t){
    if (t == NULL) return 0;
    if (t->pLeft != NULL && t->pRight != NULL)
    // Dem Mot Con: if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
        return 1 + DemHaiCon(t->pLeft) + DemHaiCon(t->pRight);
    return DemHaiCon(t->pLeft) + DemHaiCon(t->pRight);
}

int DeleteNode(Tree &t, int x) {
    if (t == NULL) return 0; // Nút không tồn tại

    if (x < t->key) {
        return DeleteNode(t->pLeft, x);
    } else if (x > t->key) {
        return DeleteNode(t->pRight, x);
    } else {
        // Nút cần xóa được tìm thấy
        if (t->pLeft == NULL && t->pRight == NULL) {
            // Trường hợp 1: Nút lá
            free (t);
            t = NULL;
        } else if (t->pLeft == NULL) {
            // Trường hợp 2: Nút có một con (con phải)
            tNode* temp = t;
            t = t->pRight;
            free (temp);
        } else if (t->pRight == NULL) {
            // Trường hợp 2: Nút có một con (con trái)
            tNode* temp = t;
            t = t->pLeft;
            free (temp);
        } else {
            // Trường hợp 3: Nút có hai con
            tNode* temp = TimMin(t->pRight); // Tìm nút nhỏ nhất trong cây con phải
            t->key = temp->key;               // Thay thế giá trị
            DeleteNode(t->pRight, temp->key); // Xóa nút nhỏ nhất trong cây con phải
        }
        return 1; // Xóa thành công
    }
}

tNode* TimNode(Tree t, int x) {
    if (t == NULL)   // Cây rỗng hoặc không tìm thấy
        return NULL;
    if (t->key == x) // Tìm thấy nút có giá trị x
        return t; // trả về
    if (x < t->key)  // Duyệt sang cây con trái
        return TimNode(t->pLeft, x);
    else             // Duyệt sang cây con phải
        return TimNode(t->pRight, x); 
}
// main
    int x = 7;
    tNode* result = TimNode(t, x);
    if (result != NULL) 
        printf("Tim thay nut co gia tri %d\n", result->key);
/////////

int KiemTraCanBang(Tree t) {
    if (t == NULL) 
        return 1; // Cây rỗng được coi là cân bằng
    int leftHeight = ChieuCaoTree(t->pLeft);
    int rightHeight = ChieuCaoTree(t->pRight);
    // Kiểm tra điều kiện cân bằng và đệ quy kiểm tra các cây con
    if (abs(leftHeight - rightHeight) <= 1 && KiemTraCanBang(t->pLeft) && KiemTraCanBang(t->pRight))
        return 1; // Cây cân bằng
    return 0; // Cây không cân bằng
}

int KiemTraCanBangHoanToan(Tree t, int index, int demNode) {
    if (t == NULL) 
        return 1; // Cây rỗng được coi là cân bằng hoàn toàn
    // Nếu index vượt quá tổng số nút, không cân bằng hoàn toàn
    if (index >= demNode)
        return 0;
    // Đệ quy kiểm tra cây con trái và phải
    return KiemTraCanBangHoanToan(t->pLeft, 2 * index + 1, demNode) &&
           KiemTraCanBangHoanToan(t->pRight, 2 * index + 2, demNode);
}

/*
void Menu() {
    printf("\nMenu:\n");
    printf("1. Them phan tu vao cay\n");
    printf("2. Xuat danh sach tang dan\n");
    printf("3. Xuat danh sach giam dan\n");
    printf("4. Kiem tra cay co phai BST\n");
    printf("5. Kiem tra cay co phai cay day du\n");
    printf("6. Tim gia tri lon nhat\n");
    printf("7. Tim gia tri nho nhat\n");
    printf("8. Tinh tong cac node\n");
    printf("9. Dem so nut trong cay\n");
    printf("10. Dem so la trong cay\n");
    printf("11. Tinh chieu cao cay\n");
    printf("0. Thoat\n");
}

int main() {
    Tree t;
    Init(t);

    int choice, value;

    do {
        Menu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                Insert(t, value);
                break;
            case 2:
                printf("Danh sach tang dan: ");
                PrintAscending(t);
                printf("\n");
                break;
            case 3:
                printf("Danh sach giam dan: ");
                PrintDescending(t);
                printf("\n");
                break;
            case 4:
                printf("Cay %s la cay BST.\n", IsBST(t) ? "" : "khong");
                break;
            case 5:
                printf("Cay %s la cay day du.\n", TreeDayDu(t) ? "" : "khong");
                break;
            case 6:
                printf("Gia tri lon nhat: %d\n", TimMax(t));
                break;
            case 7:
                printf("Gia tri nho nhat: %d\n", TimMin(t));
                break;
            case 8:
                printf("Tong cac gia tri trong cay: %d\n", CongNode(t));
                break;
            case 9:
                printf("So nut trong cay: %d\n", DemNode(t));
                break;
            case 10:
                printf("So la trong cay: %d\n", DemLa(t));
                break;
            case 11:
                printf("Chieu cao cua cay: %d\n", ChieuCaoTree(t));
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
*/