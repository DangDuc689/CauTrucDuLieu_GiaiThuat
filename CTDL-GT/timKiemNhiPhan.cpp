#include <stdio.h>

/*
    https://www.youtube.com/watch?v=B1Wl5fbluIM (giải thích chi tiết)

    * thuật toán BinarySearch chỉ được sử dụng khi "mảng đã được sắp xếp"

    phần còn kém: phân tích left, right. 
        Nếu a[mid] > x (duyệt qua bên phải) -> right = mid - 1;
        Ngược lại a[mid] < x (duyệt qua bên trái) -> left = mid + 1;

*/

int BinarySearch(int a[], int n, int x){
    int left = 0;
    int right = n-1;

    while (left <= right){
        int mid = (left + right) / 2; // tìm mid (kiểu tính trung bình cái mảng ra)

        if (a[mid] == x) 
            return mid;
        else if (a[mid] > x) // điều kiện có thể thay đổi tùy theo [ Mảng ] GIẢM DẦN hay TĂNG DẦN
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main(){
    int n, x;
    scanf ("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    scanf ("%d", &x);
    
    printf ("vi tri thu x la: %d", BinarySearch(a, n, x));
    return 0;
}