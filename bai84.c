#include<stdio.h>
#include<stdlib.h>

int Part(int K[], int LB, int UB) {
    int i = LB,m;
    int j = UB ;
    int pivot = K[(LB+UB)/2];
    while (i < j) {
        while (K[i] < pivot) i++;
        while (K[j] > pivot) j--;
        if (i < j) {
            m = K[i];
            K[i] = K[j];
            K[j] = m;
            i++;
            j--;
        }
    }
    if (pivot > K[j]) {
        m = pivot;
        pivot = K[j];
        K[j] = m;
    }
    return j;
}

void QuickSort(int K[], int LB, int UB) {
    int j;
    if (LB < UB) {
        j = Part(K,LB,UB);
        QuickSort(K,LB,j-1);
        QuickSort(K,j+1,UB);
    }
}
void print_array(int k[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", k[i]);
    }
}

int main(void) {
    int K[12]={0,42,23,74,11,65,58,94,36,99,87,30000};
    int n=sizeof(K)/sizeof(K[0]);
    printf("\nMang truoc khi sap xep: ");
    print_array(K, n);
    QuickSort(K, 0, n-1);
    printf("\nMang sau khi sap xep: ");
    print_array(K, n);
    return 0;
}