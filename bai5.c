#include <stdio.h>
#include <stdlib.h>

void select_sort(int k[], int n){
	for(int i=0;i<n-1;++i){
		int m=i;
		for(int j=i+1;j<n;++j){
			if(k[j] < k[m]) m=j;
		}
		if(m!=i){
			int x = k[i];
			k[i] = k[m];
			k[m] = x;
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
	for(int i = 0;i < n-1;++i){
		for(int j = n;j>i;j--){
			if(k[j] < k[j-1]){
				int x = k[j];
				k[j] = k[j-1];
				k[j-1] = x;
			}
		}
	}
	
}

int main(){
	int k[] = {12,29,11,49,1,20,100};
	int n = sizeof(k)/sizeof(k[0]) - 1;
	// select_sort(k,n);
	insert_sort(k,n);
	// bubble_sort(k,n);
	for(int i=0;i<n;++i){
		printf("%d ",k[i]);
	}
	return 0;
}