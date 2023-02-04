#include <stdio.h>
#include <stdlib.h>

void select_sort(int k[], int n){
	int i,j,m,x;
	for(i=0;i<n-1;i++){
		m=i;
		for(j=i+1;j<n;++j){
			if(k[j] < k[m]) m=j;
		}
		if(m!=i){
			x=k[i];
			k[i]=k[m];
			k[m]=x;
		}
	}
}

void insert_sort(int k[], int n){
	int i,j,x;
	for (i = 2 ; i < n ; i++) {
        x = k[i];
        j = i - 1;
        while (x < k[j]) {
            k[j+1] = k[j];
            j = j - 1;
        }
        k[j+1] = x;
    }
}


void bubble_sort(int k[], int n){
	int i,j,x;
	for(i=0;i<n;++i){
		for(j=n-1;j>i;j--){
			if(k[j]<k[j-1]){
				x=k[j];
				k[j]=k[j-1];
				k[j-1]=x;
			}
		}
	}
}


int main(){
	int k[] = {12,29,11,49,1,20,100};
	int n = sizeof(k)/sizeof(k[0]);
	// select_sort(k,n);
	// insert_sort(k,n);
	bubble_sort(k,n);
	for(int i=0;i<n;++i){
		printf("%d ",k[i]);
	}
	return 0;
}