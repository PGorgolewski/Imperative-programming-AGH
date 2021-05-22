#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

uint64_t odd(uint64_t x);

int main() {
    uint64_t s=0,n;

    scanf("%"PRIu64, &n);

    // suma k-pierwszych liczb nieparzystych to k*k
    // suma dla 2,4,6,... jest taka sama jak 1,2,3,...
    while (n > 0){
        if (n % 2 == 1) {  // nieparzyste n
        s+=odd((n+1)/2);   
        }
        else { // parzyste n
        s += odd(n/2);
        }
        n /= 2;
    }

    printf("%" PRIu64, s);

    return 0;
}

uint64_t odd(uint64_t x){
    return x*x;
}