#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int index(int a, int n);

int main() {
    int n,k;
    unsigned int n2;
    int best = 0;

    scanf("%d %d", &n, &k);
    n2 = (unsigned int) n;

    int ***A = (int ***)calloc(n2, sizeof(int **));
    for (int i=0; i<n; i++) {
        A[i] = (int **)calloc(n2, sizeof(int*));
        for (int j=0; j<n; j++){
            A[i][j] = (int *)calloc(5, sizeof(int)); 
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &A[i][j][0]);
            if (i==0 || j==0){
                for (int z=1; z<5; z++) A[i][j][z] = A[i][j][0];
            }
            
        }
    }

    /* A[i][j][x] - co oznacza x dla liczby w wierszu i i kol j ?
    dla x=0: liczba z inputu
    dla x=1: max odcinek w prawo zaczynajac od tego elementu
    dla x=2: max odcinek w prawo-dol zaczynajac od tego elementu
    dla x=3: max odcinek w dol zaczynajac od tego elementu
    dla x=4: max odcinek w lewo-dol zaczynajac od tego elemetu */

    for (int i=0; i<n; i++){
        for (int z=1; z<k; z++){ //warunki początkowe
            A[i][0][1] += A[i][index(0+z, n)][0];
            A[0][i][2] += A[index(0+z, n)][index(i+z, n)][0];
            A[0][i][3] += A[index(0+z, n)][i][0];
            A[0][i][4] += A[index(0+z, n)][index(i-z, n)][0];
        }
        
        best = max(best, max(A[i][0][1], max(A[0][i][2], max(A[0][i][3], A[0][i][4]))));
    }

    if (k==n) { // war poczatkowe utworzyly wszystkie mozliwe odcinki
        printf("%d", best);
        return 0;
    }

    for (int i=1; i<n; i++){
        for (int j=1; j<n; j++){
            A[i][j][1] = A[i][index(j-1,n)][1];
            A[i][j][1] += A[i][index(j+k-1,n)][0] - A[i][index(j-1,n)][0];

            A[i][j][2] = A[index(i-1,n)][index(j-1,n)][2];
            A[i][j][2] += A[index(i+k-1,n)][index(i+k-1,n)][0] - A[index(i-1,n)][index(j-1,n)][0];

            A[i][j][3] = A[index(i-1,n)][j][3];
            A[i][j][3] += A[index(i+k-1,n)][j][0] - A[index(i-1,n)][j][0];

            A[i][j][4] = A[index(i-1,n)][index(j+1,n)][4];
            A[i][j][4] += A[index(i+k-1,n)][index(j-k+1,n)][0] - A[index(i-1,n)][index(j+1,n)][0];

            best = max(best, max(A[i][j][1], max(A[i][j][2], max(A[i][j][3], A[i][j][4]))));
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
    if (a >= 0 && a<n) return a;
    if (a>=n) return a%n;
    return n+a;
}