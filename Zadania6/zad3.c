#include <stdio.h>

int main() {
    int n,m,x1,x2;
    int res = 0;

    scanf("%d %d", &n, &m);
    int t[n][n];

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){ //bedziemy uzywac tylko gornego trojkata z tablicy (zalozenie i<j)
            t[i][j] = 0; //0 -> polaczenie miedzy i oraz j jest czarne 
        }
    }

    for (int i=0; i<m; i++){
        scanf("%d %d", &x1, &x2);
        x1--;
        x2--; //zeby pasowaly indeksy
        t[x1][x2] = 1; //polaczenie miedzy x1 a x2 jest czerwone
    }

    for (int i=0; i<n-2; i++){
        for (int j=i+1; j<n-1; j++){
            for (int z=j+1; z<n; z++){
                if (t[i][j] == t[i][z] && t[i][j] == t[j][z]) res++;
            }
        }
    }

    printf("%d", res);

    return 0;
}