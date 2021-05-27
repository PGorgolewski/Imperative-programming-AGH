#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#define N 10000
#define M 100000000

int main(){
    int32_t k = (int32_t) (log2(M)+1);

    int32_t *T = (int32_t *)calloc((uint32_t) (N+4*k), sizeof(int32_t));

    for (int i=0; i<N+2*k; i++) T[i]=0;
    int32_t s=2*k, n, z, last, tmp, curr, p;

    scanf("%"SCNd32, &n);
    for (int i=0; i<n; i++){
        scanf("%"SCNd32" %"SCNd32, &z, &p);
        T[s+z] = p;
    }
    last = s+z;

    z=0;
    while(s+z <= last){
        if (T[s+z] >= 3){ //robimy rozladowanie
            tmp = T[s+z]/3; 
            T[s+z-2] += tmp;
            T[s+z+2] += tmp;
            T[s+z] -= 3*tmp;

            if (s+z+2 > last) last = s+z+2;

            z-=2;         
        }
        else{
            z++;
        }
    }

    curr = last-1;

    while(curr >= 0){
        if (T[curr] > 0 && T[curr+1] > 0){
            // ruch w prawo z curr
            T[curr]--;
            T[curr+1]--;
            T[curr+2]++;
            curr += 2;
        }
        else if(T[curr] == 2 && T[curr-1] > 0){
            curr--;
        }
        else if(T[curr] == 2 && T[curr+1] == 0){
            // skok lewy z curr i skok prawy z curr - 1
            T[curr] = 0;
            T[curr-2]++;
            T[curr+1]++;
            curr++;
        }
        else if(T[curr] == 3){
            // rozladuj
            T[curr-2]++;
            T[curr+2]++;
            T[curr] = 0;
            curr += 2;
        }
        else curr--;
    }

    for(int i=0; i<N+4*k; i++){
        if (T[i] == 0) continue;
        
        tmp = -2*k+i;
        printf("%"PRId32" ", tmp);
    }

    return 0;
}
