#include <stdio.h>
#include <stdlib.h>

int mainpow(long G);
void binaryG(long G, int p, int GG[p]);
void binaryX(long x ,int p, int GG[p], int A[p]);
int comp (const void * elem1, const void * elem2);

// zal ze podane liczby sa w kolejnosci rosnacej
int main(){
    int N, x, p, res=0;
    long G;

    scanf("%d %ld", &N, &G);

    long *T = (long *)calloc((unsigned int) N, sizeof(long));
    for (int i=0; i<N; i++) scanf("%ld", &T[i]);
    
    qsort(T, (unsigned int) N, sizeof(*T), comp);

    p = mainpow(G);

    int *A = (int *)calloc((unsigned int) p, sizeof(int)); 
    int *GG = (int *)calloc((unsigned int) p, sizeof(int));

    binaryG(G,p,GG);
    
    x=0;
    while (x<N && T[x] < G) {
        x++;
    }

    if (T[x] == G) { 
        res++;
    }

    for (int i=0; i<x; i++){
        // spr all liczby na id od 0 do x-1
        binaryX(T[i],p, GG, A);
    }

    x=N;
    for (int i=0; i<p; i++) {
        if (GG[i] == 0) continue;
        if (x>GG[i]) x=GG[i];
    }

    res = res + x-1;

    printf("%d", res);

    return 0;
}

int mainpow(long G){
    int res = 0;
    while (G>0) {
        res++;
        G /= 2;
    }

    return res;
}

void binaryG(long G, int p, int GG[p]){
    for (int i=0; i<p; i++) {
        GG[p-i-1] = G%2;

        G /= 2;
    }
}

void binaryX(long x ,int p, int GG[p], int A[p]){
    int i=0;
    while (x>0){
        A[p-1-i] = x%2;
        x /= 2;
        if (GG[p-1-i] == 0 && A[p-1-i]==1) return;
        
        i++;
    }

    for (int k=p-i; k<p; k++){
        if (A[k] == 1) GG[k]++;
    }
}

int comp (const void * elem1, const void * elem2) {
    if( *(long int*)elem1 - *(long int*)elem2 < 0 ) return -1;

    if( *(long int*)elem1 - *(long int*)elem2 > 0 ) return 1;

    return 0;
}