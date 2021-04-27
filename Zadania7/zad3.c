#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(){
    unsigned int n,k,l;
    int sum, res = 0;

    scanf("%d %d %d", &n, &k, &l);

    int **T = (int **)calloc(n, sizeof(int **));
    for (int i=0; i<n; i++) {
        T[i] = (int *)calloc(n, sizeof(int));
    }

    int **P = (int **)calloc(k, sizeof(int **));
    for (int i=0; i<n; i++) {
        P[i] = (int *)calloc(l, sizeof(int));
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &T[i][j]);
        }
    }

    for (int i=0; i<k; i++){
        for (int j=0; j<l; j++){
            scanf("%d", &P[i][j]);
        }
    }

    for (int i=0; i<=n-k; i++){
        for (int j=0; j <= n-l; j++){
            sum = 0;
            for (int k1 = 0; k1 < k; k1++){
                for (int l1 = 0; l1 < l; l1++){
                    if (P[k1][l1] == 1) sum+=T[i+k1][j+l1];
                }
            }
            res = max(res, sum);
        }
    }

    printf("%d", res);

    return 0;
}

int max(int a, int b){
    if (a>=b) return a;
    return b;
}