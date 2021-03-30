#include <stdio.h>

int main(){
    int n,r;
    int sum;

    scanf("%d %d", &n, &r);

    int t[n][n];
    int w[n][n];

    for(int i=0; i<n*n; i++){
        scanf("%d", &t[i/n][i%n]);
    }

    for(int l=0; l<n*n; l++){
        sum = 0;
        for(int i=-r; i<=r; i++){ //wiersze
            if (l/n + i < 0 || l/n + i >= n) continue;
            for(int j=-r; j<=r; j++) { //kolumny
                if (l%n + j < 0 || l%n + j >= n) continue;
                sum += t[l/n + i][l%n + j];
            }   
        }
        w[l/n][l%n] = sum;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", w[i][j]);
        }
        printf("\n");
    }

    return 0;
}