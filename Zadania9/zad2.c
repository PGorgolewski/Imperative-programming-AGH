#include <stdio.h>
#include <stdlib.h>

int check(long maxVal, short T[maxVal], long currM, short N, long M);

int main(){
    short N;
    int res=0;
    long M, tmp=1, maxVal=1, k;

    scanf("%hu %ld", &N, &M);

    if (M==1){
        printf("0");
        return 0;
    }

    for (int i=1; i<N; i++){
        tmp *= 2;
        maxVal += tmp;
    }

    maxVal++;

    short *T = (short *)calloc((unsigned long) maxVal, sizeof(short));

    for (int i=0; i<maxVal; i++) T[i] = 0;

    k = (maxVal-1)/M;
    
    for (long i=1; i<=k; i++){
        res += check(maxVal,T,i*M, N, M);
    }

    printf("%d", res);

    return 0;
}

int check(long maxVal, short T[maxVal], long currM, short N, long M){
    short *G = (short *)calloc((unsigned short) N, sizeof(short));
    long tmp = currM, tmp2, pow;
    int r = 0;

    for (int i=0; i<N; i++){
        G[N-1-i] = (short) (tmp % 2);
        tmp /= 2; 
    }

    for (int i=0; i<N; i++){
        G[i]++;
        G[i] %= 2;

        tmp2 = 0;
        pow = 1;

        for (int j=0; j<N; j++){
            if (G[N-1-j]==1){
                tmp2 += pow;
            }

            pow *= 2;
        }

        if (tmp2 % M != 0 && T[tmp2] == 0){
            T[tmp2] = 1;
            r++;
        }

        G[i]++;
        G[i] %= 2;
    }

    return r;
}