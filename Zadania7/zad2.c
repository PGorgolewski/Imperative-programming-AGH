#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int index(int a, int n);

int main() {
    int n, k, a;
    unsigned int n2;
    int best = 0;
    int t[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}, {-1,0}, {-1,1}};

    scanf("%d %d", &n, &k);
    n2 = (unsigned int) n;

    int **A = (int **)calloc(n2, sizeof(int *));
    for (int i=0; i<n; i++) {
        A[i] = (int *)calloc(n2, sizeof(int));
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int q = 0; q<8; q++){
                a = 0;
                for (int c = 0; c<k; c++){
                    a += A[index(i+t[q][0]*c, n)][index(j+t[q][1]*c, n)];
                }
                best = max(best, a);  
            }
        }
    }

    printf("%d", best);

    return 0;
}

int max(int a, int b){
    if (a>=b) return a;
    return b;
}

int index(int a, int n){
    if (a >= 0) return a%n;
    return n+a;
}