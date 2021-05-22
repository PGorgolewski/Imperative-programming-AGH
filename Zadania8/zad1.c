#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int8_t len(int64_t s);
// zal ze X=abcd
// S = 1111a + 111b + 11c + d
// a = S//1111, n %= 1111, b = n//111 etc
int main() {
    int64_t s, tmp, x=0, k=0;
    int8_t l;

    scanf("%"PRId64, &s);
    l = len(s);

    for (int i=0; i<l; i++){
        k = k*10 + 1;
    }

    tmp = s;
    while (k>0){
        x = x*10 + tmp/k;
        tmp %= k;
        k /= 10;
    }
    
    //spr czy suma jest poprawna
    tmp = x;
    k=0;
    while (tmp>0){
        k += tmp;
        tmp /= 10;
    }

    if (k==s) printf("%" PRId64, x);
    else printf("-1");

    return 0;
}

int8_t len(int64_t s){
    int8_t c = 0;
    while (s>0){
        c++;
        s /= 10;
    }

    return c;
}