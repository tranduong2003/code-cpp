#include <stdio.h>
#include <stdlib.h>

int Part(int K[], int LB, int UB){
    int i,m;
    i = LB + 1;
    int j = UB;

    while(i<j){
        while(K[i] < K[LB]) i = i + 1;
        while(K[j] > K[LB]) j = j - 1;
        if(i<j){
            m = K[i];
            K[i] = K[j];
            K[j] = m;
            i = i + 1;
            j = j - 1;
        }
    }
    if(K[LB] > K[j]){
        m = K[LB];
        K[LB] = K[j];
        K[j] = m;
    }
    return j;
}

void QuickSort(int K[], int LB, int UB){
    int j;
    if(LB < UB){
        j = Part(K,LB,UB);
        QuickSort(K,LB,j-1);
        QuickSort(K,j+1,UB);
    }
}

void print_array(int k[], int n){
    int i;
    for(i=0;i<=n;++i){
        printf("%d ",k[i]);
    }
}

int main(){
    int K[12]={0,42,23,74,11,65,58,94,36,99,87,30000};
    printf("\nMang truoc khi sap xep: ");
    print_array(K, 11);
    QuickSort(K,0,11);
    printf("\nMang sau khi sap xep: ");
    print_array(K, 11);
    return 0;
}