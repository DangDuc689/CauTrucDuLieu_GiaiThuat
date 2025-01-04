#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc NODE
typedef struct node {
    int heso;   // Hệ số
    int somu;   // Số mũ
    struct node* pNext;
} NODE;

// Định nghĩa cấu trúc DATHUC
typedef struct dathuc {
    NODE* pHead;
    NODE* pTail;
} DATHUC;

// Hàm khởi tạo danh sách đa thức
void Init(DATHUC &dt) {
    dt.pHead =  dt.pTail = NULL;
}

// Hàm tạo một node mới
NODE* CreateNode(int heso, int somu) {
    NODE* p = (NODE*)malloc(sizeof(NODE));
    if (p != NULL) {
        p->heso = heso;
        p->somu = somu;
        p->pNext = NULL;
    }
    return p;
}

// Hàm thêm một node vào cuối danh sách
void InserTail(DATHUC &dt, NODE* p) {
    if (dt.pHead == NULL) {
        dt.pHead = dt.pTail = p;
    } else {
        dt.pTail->pNext = p; // p->pNext = dt.pHead; 
        dt.pTail = p;        // dt.pHead = p;
    }
}

// Hàm tính giá trị một đơn thức
int TinhGiaTriDonThuc(NODE* p, int x) {
    int result = 1;
    for (int i = 0; i < p->somu; i++) {
        result *= x;
    }
    return p->heso * result;
}
// #include <math.h>
// int TinhGiaTriDonThuc(NODE* p, int x) {
//     return p->heso * pow(x, p->somu);
// }


// Hàm tính giá trị đa thức
int TinhGiaTriDaThuc(DATHUC &dt, int x) {
    int result = 0;
    for (NODE* p = dt.pHead; p != NULL; p = p->pNext)
        result += TinhGiaTriDonThuc(p, x);
    return result;
}

// // Hàm sắp xếp đa thức tăng dần theo hệ số
// void SapXepHeSoTangDan(DATHUC &dt) {
//     for (NODE* i = dt.pHead; i != dt.pTail; i = i->pNext) {
//         for (NODE* j = i->pNext; j != NULL; j = j->pNext) {
//             if (i->heso > j->heso) {
//                 int tempHeso = i->heso;
//                 int tempSomu = i->somu;
//                 i->heso = j->heso;
//                 i->somu = j->somu;
//                 j->heso = tempHeso;
//                 j->somu = tempSomu;
//             }
//         }
//     }
// }

// Hàm sắp xếp đa thức giảm dần theo số mũ
void SapXepSoMuGiamDan(DATHUC &dt) {
    for (NODE* i = dt.pHead; i != dt.pTail; i = i->pNext) {
        for (NODE* j = i->pNext; j != NULL; j = j->pNext) {
            if (i->somu < j->somu) {
                int tempHeso = i->heso;
                int tempSomu = i->somu;
                i->heso = j->heso;
                i->somu = j->somu;
                j->heso = tempHeso;
                j->somu = tempSomu;
            }
        }
    }
}

// Hàm tìm đơn thức có giá trị nhỏ nhất trong đa thức
NODE* TimDonThucNhoNhat(DATHUC &dt, int x) {
    NODE* min = dt.pHead;
    int minValue = TinhGiaTriDonThuc(min, x);

    for (NODE* i = dt.pHead->pNext; i != NULL; i = i->pNext) {
        int value = TinhGiaTriDonThuc(i, x);
        if (value < minValue) {
            minValue = value;
            min = i;
        }
    }
    return min;
}

// Hàm tìm đơn thức có số mũ chẵn đầu tiên trong đa thức
NODE* TimDonThucSoMuChan(DATHUC &dt) {
    for (NODE* i = dt.pHead; i != NULL; i = i->pNext) {
        if (i->somu % 2 == 0) {
            return i;
        }
    }
    return NULL;
}

// Hàm liệt kê các đơn thức có hệ số dương
void DonThucHeSoDuong(DATHUC &dt) {
    for (NODE* i = dt.pHead; i != NULL; i = i->pNext) {
        if (i->heso > 0) {
            printf("%dx^%d\n", i->heso, i->somu);
        }
    }
}

// Hàm đếm số lượng đơn thức có số mũ chẵn
int DemDonThucSoMuChan(DATHUC &dt) {
    int dem = 0;
    for (NODE* i = dt.pHead; i != NULL; i = i->pNext) {
        if (i->somu % 2 == 0) {
            dem++;
        }
    }
    return dem;
}

// Hàm chèn một đơn thức vào danh sách theo thứ tự tăng dần theo hệ số
void ChenDonThucTangDan(DATHUC &dt, int heso, int somu) {
    NODE* p = CreateNode(heso, somu);
    if (dt.pHead == NULL || dt.pHead->heso >= heso) {
        p->pNext = dt.pHead;
        dt.pHead = p;
        if (dt.pTail == NULL) {
            dt.pTail = p;
        }
        return;
    }

    NODE* i = dt.pHead;
    while (i->pNext != NULL && i->pNext->heso < heso) {
        i = i->pNext;
    }

    if (i->pNext != NULL && i->pNext->somu == somu) {
        i->pNext->heso += heso;
        free(p);
        return;
    }

    p->pNext = i->pNext;
    i->pNext = p;
    if (p->pNext == NULL) {
        dt.pTail = p;
    }
}


// Hàm xóa đơn thức có hệ số âm đầu tiên
void XoaDonThucHeSoAmDau(DATHUC &dt) {
    if (dt.pHead == NULL) return;

    if (dt.pHead->heso < 0) {
        NODE* temp = dt.pHead;
        dt.pHead = dt.pHead->pNext;
        if (dt.pHead == NULL) {
            dt.pTail = NULL;
        }
        free(temp);
        return;
    }

    NODE* i = dt.pHead;
    while (i->pNext != NULL && i->pNext->heso >= 0) {
        i = i->pNext;
    }

    if (i->pNext != NULL) {
        NODE* temp = i->pNext;
        i->pNext = temp->pNext;
        if (temp == dt.pTail) {
            dt.pTail = i;
        }
        free(temp);
    }
}


// Hàm in đa thức
void InDaThuc(DATHUC &dt) {
    for (NODE* p = dt.pHead; p != NULL; p = p->pNext) {
        printf("%dx^%d ", p->heso, p->somu);
        if (p->pNext != NULL && p->pNext->heso > 0) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Hàm in đa thức
// void InDaThuc(DATHUC &dt) {
//     for (NODE* p = dt.pHead; p != NULL; p = p->pNext) {
//         if (p != dt.pHead && p->heso > 0) {
//             printf("+ ");
//         }
//         printf("%dx^%d ", p->heso, p->somu);
//     }
//     printf("\n");
// }

// int main() {
//     DATHUC dt;
//     Init(dt);

//     // Khởi tạo đa thức mẫu: 5x^6 + 7x^5 - 10x^3 + 2x^2 + 16
//     InserTail(dt, CreateNode(-5, 6));
//     InserTail(dt, CreateNode(-7, 5));
//     InserTail(dt, CreateNode(-10, 3));
//     InserTail(dt, CreateNode(-2, 2));
//     InserTail(dt, CreateNode(16, 0));

//     // In đa thức ban đầu
//     printf("Da thuc ban dau: ");
//     InDaThuc(dt);

//     // Tính giá trị đa thức tại x = 2
//     int x = 2;
//     printf("Gia tri da thuc tai x = %d: %d\n", x, TinhGiaTriDaThuc(dt, x));

//     // Sắp xếp đa thức tăng dần theo hệ số
//     SapXepHeSoTangDan(dt);
//     printf("Da thuc sau khi sap xep tang dan theo he so: ");
//     InDaThuc(dt);

//     // Sắp xếp đa thức giảm dần theo số mũ
//     SapXepSoMuGiamDan(dt);
//     printf("Da thuc sau khi sap xep giam dan theo so mu: ");
//     InDaThuc(dt);

//     // Tìm đơn thức có giá trị nhỏ nhất tại x = 2
//     NODE* minNode = TimDonThucNhoNhat(dt, x);
//     if (minNode) {
//         printf("Don thuc co gia tri nho nhat tai x = %d: %dx^%d\n", x, minNode->heso, minNode->somu);
//     }

//     // Tìm đơn thức có số mũ chẵn đầu tiên
//     NODE* chanNode = TimDonThucSoMuChan(dt);
//     if (chanNode) {
//         printf("Don thuc co so mu chan dau tien: %dx^%d\n", chanNode->heso, chanNode->somu);
//     }

//     // Liệt kê các đơn thức có hệ số dương
//     printf("Cac don thuc co he so duong:\n");
//     DonThucHeSoDuong(dt);

//     // Đếm số lượng đơn thức có số mũ chẵn
//     int soLuongChan = DemDonThucSoMuChan(dt);
//     printf("So luong don thuc co so mu chan: %d\n", soLuongChan);

//     // Chèn một đơn thức vào danh sách
//     ChenDonThucTangDan(dt, 3, 4); // Ví dụ: thêm 3x^4
//     printf("Da thuc sau khi chen don thuc 3x^4: ");
//     InDaThuc(dt);

//     // Xóa đơn thức có hệ số âm đầu tiên
//     XoaDonThucHeSoAmDau(dt);
//     printf("Da thuc sau khi xoa don thuc co he so am dau tien: ");
//     InDaThuc(dt);

//     return 0;
// }
