#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Ham bubbleSort
void bubbleSort(int arr[], int n, int *comps, int *swaps){
    *comps = 0;
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            (*comps)++; //Cong 1 buoc so sanh
            if(arr[j - 1] > arr[j]) {
                //Chuyen doi vi tri
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                (*swaps)++; //Cong 1 buoc doi vi tri
            }
        }
    }
}

//Ham initializeArray
void initializeArray(int arr[], int n, int min, int max){
    for (int i = 0; i < n; i ++)
        arr[i] = min + rand() % (max - min + 1);
        //Sinh ngau nhien gia tri trong khoang [min, max]
}

int main(){
    int min = -100;
    int max = 100;
    int comps;
    int swaps;
    int arr[10000];
    int k[5] = {10, 20, 50, 100, 1000};

    time_t t;
    srand((unsigned)time(&t));

    for (int i = 0; i < 5; i++){
        int n = k[i];
        printf("n = %d \n", n);

        //Xuat mang ngau nhien
        printf("Ham sinh cac gia tri ngau nhien:\n");
        initializeArray(arr, n, min, max); //Sinh mang
        for (int i = 0; i < n; i++){
            printf("%d  ", arr[i]);
        }
        printf("\n");

        //Xuat mang da sap xep
        printf("Ham sau khi sap xep tang dan:\n");
        bubbleSort(arr, n, &comps, &swaps);
        for (int i = 0; i < n; i++){
            printf("%d  ", arr[i]);
        }
        printf("\n");
        printf("So buoc so sanh: %d\n",comps);
        printf("So buoc doi vi tri: %d\n",swaps);
    }
    return 0;
}
