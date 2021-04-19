#include <stdio.h>

int main(){
    int n, k;
    int l=1, z=0;

    scanf("%d", &n);

    int T[n][n];

    k = n/2;
    if (n%2==0) k--; //k+1 to ilosc rozpoczetych obrotow

    while(z<=k){
        for(int i=z; i<n-z; i++){ //gora
            T[z][i] = l;
            l++;
        }
        for(int i=1+z; i<n-z; i++) { //prawo
            T[i][n-1-z] = l;
            l++;
        } 
        for(int i=n-2-z; i>=0+z; i--){ //dol
            T[n-1-z][i] = l;
            l++;
        }
        for(int i=n-2-z; i>=1+z; i--) { //lewo
            T[i][z] = l;
            l++;
        }

        z++;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}