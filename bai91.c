#include <stdio.h>
#include <stdlib.h>

void ADJUST(int k[], int i, int n){
    int KEY = k[i];
    int j = 2*i;
    while(j<=n){
        if((j<n) && (k[j] < k[j+1])) j++;
        if(KEY > k[j]){
            k[j/2] = KEY;
            return;
        }
        k[j/2] = k[j];
        j = 2*j;
    }
    k[j/2] = KEY;
}



void HeapSort(int k[], int n){
    int i;
    for(i=n/2;i>=0;i--){
        ADJUST(k,i,n);
    }

    for(i=n-1;i>=0;i--){
        int temp = k[0];
        k[0] = k[i];
        k[i] = temp;
        ADJUST(k,1,i);
    }
}


void in(int K[], int n){
    for(int i=0;i<n;++i){
        printf("%d ",K[i]);
    }
}

int main(){
    int K[] = {0,1,12,9};
    int n = sizeof(K)/sizeof(K[0]);
    HeapSort(K,n);
    printf("Mang sau khi sap xep la: \n");
    in(K,n);
    return 0;
}