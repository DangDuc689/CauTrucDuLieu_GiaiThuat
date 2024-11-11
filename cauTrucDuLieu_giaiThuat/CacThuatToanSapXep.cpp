
chèn (đúng nghĩa)


void InsertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void SelectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        int iMin = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[iMin])
                iMin = j;
        }
        int temp = arr[i];      // swap
        arr[i] = arr[iMin];
        arr[iMin] = temp;
    }
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}