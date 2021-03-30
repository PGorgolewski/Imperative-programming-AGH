#include <stdio.h>
#define N 160

int main(){
    int t[N], n, k, p, l, tmp;

    scanf("%d", &n);

    for(int i=0; i<N-1; i++){
        t[i] = 0;
    }

    t[N-1] = 1;

    l = 159;
    for(int j=2; j<=n; j++){
        k = 159;
        p = 0;
        while(k >= l || p > 0){
            tmp = j*t[k] + p;
            p = tmp/10;
            t[k] = tmp%10;
            k-=1;
        }
        l = k+1;
    }

    for(;l<N;l++){
        printf("%d", t[l]);
    }
    
    return 0;
}