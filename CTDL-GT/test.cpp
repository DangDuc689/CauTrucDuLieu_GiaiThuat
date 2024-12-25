#include <string.h>
void InterchangeSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

5
2 3 4 5 9
      

void InsertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int x = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}


                        x=6                   
        2   4   6   7   10
                    j   i          
// -1   0   1   2   3   4     (thu tu)

void BubbleSort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (j = n-1; j > i; j--){
            if (a[j] < a[j-1]){
                swap(a[j], a[j-1]);
            }
        }
    }
}
      

        0   3   5   7   9  
            i       j
                j-1
    //  0   1   2   3   4


void SelectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int x = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[x])
                x = j;
        }
        swap(a[x], a[i]);
    }
}


        2   4   5   7   8
                    i   j                            
                    x                   
    //  0   1   2   3   4


void QuickSort(int a[], int left, int right){
    int x = a[(left + right) / 2];
    int i = left;
    int j = right;

    do{
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while(i < j);

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

                    x=2
        2   9   3   5   4   7   8
        j   i   
    //  0   1   2   3   4   5   6

            left
            2               

            right
                    x=5
            4   3   5   9   7   8
                j       i
        //  0   1   2   3   4   5

                left 
                x=4
                3   4
                j   i
            //  0   1

                right
                    x=9
                5   8   7   9
                        j   i
            //  0   1   2   3   

                    left
                        x=8  
                    5   7   8
                        j   i
                //  0   1   2
        

void InterchangeSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

void BubbleSort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = n-1; j > i; j--){
            if (a[j] < a[j-1])
                swap(a[j], a[j-1]);
        }
    }
}

void SelectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){  
        int x = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[x])
                x = j;
        }
        swap(a[i], a[x]);
    }
}

void InsertionSort(char s[]){
    int n = strlen(s);
    for (int i = 1; i < n; i++){
        int x = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void QuickSort(int a[], int left, int right){
    int x = a[(left + right) / 2];
    int i = left;
    int j = right;

    do{
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while(i < j);

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}
