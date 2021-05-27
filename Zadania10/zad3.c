#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add1(int n, int T[n]){
    int m = n-1;
    T[m]++;

    while(T[m] > 1 && m>0){
        T[m] = 0;
        m--;
        T[m]++;
    }
} 

int main(){
    int n,m,last, curr,tmp1,tmp2;
    int k=0;
    long result = 0;
    scanf("%d %d %d", &n, &m, &last);
    char binSTR[n+1];

    int **A = (int **)calloc((unsigned int) m, sizeof(int *));
    for (int i=0; i<m; i++) {
        A[i] = (int *)calloc(3, sizeof(int));
    }

    int **B = (int **)calloc(2, sizeof(int *));
    for (int i=0; i<2; i++) {
        B[i] = (int *)calloc((unsigned int) n, sizeof(int));
    }

    int *K = (int *)calloc((unsigned int) m, sizeof(int));

    //ustawiam jako pierwszą tą mniejszą
    for (int i=0; i<m; i++){
        scanf("%d %d", &tmp1, &tmp2);
        A[i][2] = 0;
        if (tmp1 > tmp2){
            A[i][0]= tmp1;
            A[i][1] = tmp2;
        }
        else{
            A[i][0] = tmp2;
            A[i][1] = tmp1;
        }
        if (A[i][0] < 0){ //obie polaczenia z sieci (obie ujemne)
            K[k]=i;
            k++;
            A[i][3]=1;
        }
        else if (A[i][0] > 0 && A[i][1] < 0 && A[(A[i][0]-1)][3]==1){ //1 dodatnia, 1 ujemna
            K[k]=i;
            k++;
            A[i][3]=1;
        }

        else if (A[i][1] > 0 && A[(A[i][0]-1)][3]==1 && A[(A[i][1]-1)][3]==1){//obie dodatnie -> z innych bramek
            K[k]=i;
            k++;
            A[i][3]=1;
        }   
    }
    
    tmp1=n-1;
    for (int i=0; i<2; i++){
        scanf("%s", binSTR);
        for (int j=0; j<n; j++){
            B[i][j] = binSTR[j] - '0';

            if (i==1 && B[i][j] == 1 && j<tmp1) tmp1=j;
        }
    }

    while(k<m){ //Po tej petli mamy ustalona kolejnosc
        for (int i=0; i<m; i++){
            if (A[i][3] == 1) continue;

            if (A[i][0] > 0 && A[i][1] < 0 && A[(A[i][0]-1)][3]==1) { //1 dodatnia, 1 ujemna
                K[k]=i;
                k++;
                A[i][3]=1;
            }

            else if (A[i][1] > 0 && A[(A[i][0]-1)][3]==1 && A[(A[i][1]-1)][3]==1){//obie ujemne
                K[k]=i;
                k++;
                A[i][3]=1;
            }   
        }
    }
    
    
    while (tmp1 < n){ //jezeli tmp1 zostanie m to zanczy ze zrobilismy wszystkie liczby
        while(tmp1 < n && B[0][tmp1] == B[1][tmp1]) tmp1++;

        for (int i=0; i<m; i++){
            curr = K[i];
            
            if (A[curr][0] < 0){ //obie ujemne
                A[curr][3] = B[0][(A[curr][0]+1) * (-1)] ^ B[0][(A[curr][1]+1) * (-1)];
            }

            else if (A[curr][1] < 0){ //1 dodatnia, 1 ujemna
                A[curr][3] = A[(A[curr][0]-1)][3] ^ B[0][(A[curr][1]+1) * (-1)];
            }

            else{//obie dodatnie
                A[curr][3] = A[(A[curr][0]-1)][3] ^ A[(A[curr][1]-1)][3];
            }   
        }

        if (A[last-1][3]==1) result++;

        add1(n, B[0]);
    }

    printf("%ld", result);
    return 0;
}