#include <stdio.h>
#include <stdlib.h>

void Merge(int b[], int h, int t, int k){
    int c[t-h+1];
    int i=0, u=h,v=t+1;
    for(i=0;i<=t-h;i++){
        c[i] = b[h+i];
    }
    i=0;
    while(i<=t-h){
        if(v<=k && b[v] < c[i]){
            b[u] = b[v];
            u++; v++;
        }
        else{
            b[u] = c[i];
            u++; i++;
        }
    }
    while(v<=k){
        b[u] = b[v];
        u++; v++;
    }
}

void MergeSort(int b[], int h, int k){
    if(k-h<1) return;
    int t = (h+k)/2;
    MergeSort(b,h,t);
    MergeSort(b,t+1,k);
    Merge(b,h,t,k);
}
void print_array(int K[], int i1, int i2) {
    int i;
    for (i = i1; i <= i2; i++) {
        printf("%d ",K[i]);
    }
}

int main() {
    int K[] = {0,4,2,6,25,2};
    int k = 5;
    printf("Mang truoc khi sap xep: ");
    print_array(K,0,k);
    MergeSort(K,0,k);
    printf("\nMang sau khi sap xep: ");
    print_array(K,0,k);
    return 0;
}