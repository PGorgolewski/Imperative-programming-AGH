#include <stdio.h>

int max(int a, int b);

int main(){
    int n,top,s;
    int maxS = 0, x=0;

    scanf("%d", &n);
    int T[n][n];
    int A[n];


    for (int i=0; i<n; i++){ //tablice T, podczas wczytywania zamieniam na historiogramy
        for(int j=0; j<n; j++){
            scanf("%d", &T[i][j]);
            if (i == 0){
                if (T[i][j] == 0){
                    T[i][j] = 1;
                    x++;
                }
                else T[i][j] = 0;
            }
            else{
                if (T[i][j] == 0){
                    T[i][j] = T[i-1][j] + 1;
                    x++;
                }
                else T[i][j] = 0;
            }
        }
    }

    if ( x == 0 || x == n*n) {
        printf("%d", x);
        return 0;
    }  
    
    s = 0; // indeks dla nastepnego na stos (0 means pusty stos)
    for (int i=0; i<n; i++){ //uzywamy historiogramow do sprawdzania najwiekszego prostokata
        for (int j=0; j<=n; j++){
            if (j == n){
                while (s!=0){
                    top = T[i][A[s-1]];
                    s--;
                    if (s != 0) {
                        x = top * (j-A[s-1]-1);
                    }
                    else{
                        x = top * j;
                    }
                    maxS = max(maxS,x);
                }
            }
            else{
                if (s == 0 || T[i][A[s-1]] <= T[i][j] ) {
                    A[s] = j;
                    s++;
                }
                else {
                    while ( s!=0 && T[i][A[s-1]] > T[i][j] ){
                        top = T[i][A[s-1]];
                        s--;
                        if (s != 0) {
                            x = top * (j-A[s-1]-1);
                        }
                        else{
                            x = top * j;
                        }
                        maxS = max(maxS,x);
                    }
                    A[s] = j;
                    s++;
                }
            }
        }
    }

    printf("%d", maxS);
    return 0;
}

int max(int a, int b){
    if (a>b) return a;
    return b;
}