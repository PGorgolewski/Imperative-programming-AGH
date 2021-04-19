#include <stdio.h>

int max(int a, int b);
int min(int a, int b);
// A[i][j] oznacza bok najwiekszego mozliwego kwadratu o dolnym prawym rogu (i,j)
// Program nie dziala dla ostatnego testu z OIOIOI (dont know why)
int main(){
    int n,k;
    int m = 0, maxS = 0, x=0;

    scanf("%d", &n);
    int T[n][n];
    int A[n][n];

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &T[i][j]);
            if (T[i][j] == 0) x++;
            if (i == 0){
                if (T[i][j] == 0) A[i][j] = 1;
                else A[i][j] = 0;
            }
            else if (j==0){}
                if (T[i][j] == 0) A[i][j] = 1;
                else A[i][j] = 0;  
            }
        }

    if ( x == 0 || x == n*n) {
        printf("%d", x);
        return 0;
    }
    
    for (int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if (T[i][j] == 0) {
                A[i][j] = min(min(A[i-1][j-1],A[i][j-1]),A[i-1][j]) + 1;
            }
            else A[i][j] = 0;
        }
    }

    for (int i=n-1; i>=0; i--){
        for (int j=n-1; j>=0; j--){
            m = A[i][j]*A[i][j];
            maxS = max(maxS, A[i][j]*A[i][j]);
            k=1;
            while(i-k >= 0 && A[i][j]<=A[i-k][j]){
                if (m >= A[i-k][j]) maxS = max(maxS, m + A[i][j]*k);
                else break;
                k++;
            }

            k=1;
            while(j-k >= 0 && A[i][j]<=A[i][j-k]){
                if (m >= A[i][j-k]) maxS = max(maxS, m + A[i][j]*k);
                else break;
                k++;
            }
        }
        if (maxS >= i*i && maxS >= n*i) break;
    }

    printf("%d", maxS);
    return 0;
}

int max(int a, int b){
    if (a>b) return a;
    return b;
}

int min(int a, int b){
    if (a<b) return a;
    return b;
}