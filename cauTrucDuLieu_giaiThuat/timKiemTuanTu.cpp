#include <stdio.h>

int timKiemTuanTu(int arr[], int n, int k){ // tim kiem vi tri thu k
    for (int i = 0; i < n; i++){
        if (arr[i] == k)
            return i; // tra ve vi tri
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
    
    printf ("vi tri thu k la: %d", timKiemTuanTu(arr, n, k));
    return 0;
}