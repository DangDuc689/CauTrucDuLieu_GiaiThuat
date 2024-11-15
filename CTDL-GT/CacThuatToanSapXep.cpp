

void InterchangeSort(int a[], int n){ // đổi chỗ trực tiếp
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

void InsertionSort(int a[], int n) { // chèn trực tiếp
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}


void SelectionSort(int a[], int n){ // chọn trực tiếp ( tìm x(max,min) khi sử dụng dạng sort này)
    for (int i = 0; i < n-1; i++){
        int x = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[x])
                x = j;
        }
        swap(a[i], a[x]);
    }
}

void BubbleSort(int a[], int n) { // nổi bọt ( chậm )
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

// Hàm Quick Sort với tham số left và right
void QuickSort(int a[], int left, int right) {
    int i, j, pivot;

    // Chọn pivot là phần tử giữa mảng
    pivot = a[(left + right) / 2];
    i = left;
    j = right;

    do {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);

    // Đệ quy sắp xếp các phần còn lại
    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}