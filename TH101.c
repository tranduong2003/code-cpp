#include <stdio.h>
#include <stdlib.h>
#define MAX 50

//Thuat toan Prim
void readData(char *filename, int G[MAX][MAX], int *pn) {
    FILE *file = fopen(filename, "r");
    int i, j;
    if (file != NULL) {
        fscanf(file, "%d", pn);
        for (i = 0; i < *pn ; i++)
            for (j = 0; j < *pn; j++)
                fscanf(file, "%d", G[i][j] );
    }
    fclose(file);
}

int prim(int G[MAX][MAX], int n) {
    int ne, i;
    int s[MAX];
    int cost = 0;

    for (i = 0; i < n; i++)
        s[i] = 0;

    ne = 0; // The number of edges in the spanning tree

    s[0] = 1; // Initialize: vertex 0 is in the spanning tree

    int i1;  //  i1 is a vertex that is in the spanning tree
    int j1;  //  j1 is a vertex that is not in the spanning tree

    // print for edge and weight
    printf("Edge : Weight\n");

    while (ne < n-1 ) {
        int min = 9999;
        for (int i = 0; i < n; i++) {
            if (s[i] == 1 ) { 
                for (int j = 0; j < n; j++) {
                    if (s[j] == 0  && G[i][j] > 0) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            i1 = i;
                            j1 = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", i1, j1, G[i1][j1]);
        s[j1] = 1;
        ne++;
        cost = cost + G[i1][j1];
    }

    printf("Cost of the minimum spanning tree: %d", cost);

    return 0;
}


int main(){
    int G[MAX][MAX];
    int n, source;
    readData("data.txt", G, &n);
    prim(G, n);
    return 0;
}