#include <stdio.h>

/*
    https://www.youtube.com/watch?v=B1Wl5fbluIM (giải thích chi tiết)

    * thuật toán BinarySearch chỉ được sử dụng khi "mảng đã được sắp xếp"

    phần còn kém: phân tích left, right. 
        Nếu arr[mid] > k (duyệt qua bên phải) -> right = mid - 1;
        Ngược lại arr[mid] < k (duyệt qua bên trái) -> left = mid + 1;

*/

int BinarySearch(int arr[], int n, int k){
    int left = 0;
    int right = n-1;

    while (left <= right){
        int mid = (left + right) / 2; // tìm mid (kiểu tính trung bình cái mảng ra)

        if (arr[mid] == k) // điều kiện có thể thay đổi tùy theo mảng GIẢM DẦN hay TĂNG DẦN
            return mid;
        else if (arr[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main(){
    int n, k;
    scanf ("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    scanf ("%d", &k);
    
    printf ("vi tri thu k la: %d", BinarySearch(arr, n, k));
    return 0;
}