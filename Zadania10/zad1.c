#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define k 31

int subAndDiv(int len, int T[len], int x, int first, int plusOrMin){
    int i=len-1, p;
    
    if (plusOrMin == 1){ //czyli mamy teraz dodatnią
        T[i] -= x;

        while (i>=0 && T[i] < 0){ //odejmowanie
            T[i]+=10;
            i--;
            T[i]-=1;
        }

        if (T[first] == 0) first++; //przez odejmowanie
    }

    else{ // czyli mamy teraz ujemną
        T[i] += x;
    
        while (i>0 && T[i] > 9){ //dodajemy
            T[i]-=10;
            i--;
            T[i]+=1;
        }

        if (T[first-1] > 0) first--; //przez dodawanie
    }
    
    
    i=first;
    while(i<len-1){
        p = T[i] % 2;
        T[i+1]+=p*10;
        T[i] /= 2;
        i++;
    }

    T[i] /= 2;

    if (T[first]==0) first++;

    return first; 
}

int main(){
    char Money[k];
    int len,m,first, tmp, plusOrMin;
    
    scanf("%s", Money);
    len = (int) strlen(Money);

    int *M = (int *)calloc((unsigned int) len+1, sizeof(int));
    int *T = (int *)calloc((unsigned int) len+1, sizeof(int));
    int *C = (int *)calloc((unsigned int) N, sizeof(int));


    M[0] = 0;
    for (int i=0; i<len; i++){
        M[i+1] = Money[i] - '0';  
    }

    len++;

    for (int i=0; i<N; i++){
        C[i] = 0;  
    }
    
    for (int z=0; z<2; z++){
        first=1;
        m=0;
        if (z==1) plusOrMin = -1;
        else plusOrMin = 1;
        for(int i=0; i<len; i++){
            T[i]=M[i];
        }
        while(m<N && first<len){
            tmp = T[len-1] % 2;
            if (tmp == 1) {
                C[m]=1;
            }
            first = subAndDiv(len,T,tmp, first, plusOrMin);
            m++;
            plusOrMin *= (-1);
        }

        if (first<len){
            printf("NO");
            for (int i=0; i<N; i++){
                C[i] = 0;
            }
        }

        else{
            for (int i=0; i<N; i++){
                if (C[i]==1){
                    C[i] = 0;
                    printf("%d ", i);
                } 
            }
        }
        printf("\n");
    }
    return 0;
} 