#include <stdio.h>
#include <stdlib.h>

int Part(int k[], int LB, int UB){
    int i, temp;
    i = LB + 1;
    int j = UB;
    while(i<j){
        while(k[i] < k[LB]) i++;
        while(k[j] > k[LB]) j--;
        if(i<j){
            temp = k[i];
            k[i] = k[j];
            k[j] = k[i];
            i++;j--;
        }
    }
    if(k[LB] > k[j]){
        temp = k[LB];
        k[LB] = k[j];
        k[j] = temp;
    }
    return j;
}


void QuickSort(int k[], int LB, int UB){
    int j;
    if(LB < UB){
        int j = Part(k,LB,UB);
        QuickSort(k,LB,j-1);
        QuickSort(k,j+1,UB);
    }
}


void print_array(int k[], int n){
    int i;
    for(i=0;i<n;++i){
        printf("%d ",k[i]);
    }
}

int main(){
    int K[12]={0,42,23,74,11,65,58,94,36,99,87,30000};
    printf("Mang truoc khi sap xep: ");
    print_array(K, 12);
    QuickSort(K,0,12);
    printf("\nMang sau khi sap xep: ");
    print_array(K, 12);
    return 0;
}