#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define N 100

int main(){
    char res[N];
    int32_t k=0,z,v;
    int64_t s,t,tmp;

    scanf("%"PRId64" %"PRId64, &s, &t);

    if (t==0){
        printf("-");
        return 0;
    }
    else if (t==s){
        return 0;
    }
    else if (t==1){
        printf("/");
        return 0;
    }

    z=1;
    tmp=s;
    while (t%tmp==0){
        tmp*=tmp;
        z++;
    }

    z--;
    while (z>0){
        tmp = (int64_t) sqrt( (double) tmp);

        v=1;
        while (tmp*v < t) {
            v+=v;
        }

        if (tmp*v == t) {
            while(1){
                double q = sqrt(v);
                if (z>1 && q - (int16_t) q == 0) {
                    //mozemy zrobic operacje *
                    res[k]='*';
                    k++;
                    tmp = (int64_t) sqrt((double) tmp);
                    v = (int16_t) sqrt(v);
                }
                else {
                    //jak nie * to +
                    res[k]='+';
                    k++;
                    v/=2;
                }

                if (z==0) {
                    if (v==1) break;
                }
                else{
                    if (tmp==s && v==1) break;
                }
            }

            k--;
            while (k>=0){
                printf("%c", res[k]);
                k--;
            }

            return 0;   
        }

        z--;
    }

    //teraz trzeba check czy dziala od 1
    tmp=2;
    z=1;
    while (t%tmp==0){
        tmp*=tmp;
        z++;
    }

    z--;
    while (z>0){
        tmp = (int64_t) sqrt( (double) tmp);

        v=1;
        while (tmp*v < t) {
            v+=v;
        }

        if (tmp*v == t) {
            while(1){
                double q = sqrt(v);
                if (z>1 && q - (int16_t) q == 0) {
                    //mozemy zrobic operacje *
                    res[k]='*';
                    k++;
                    tmp = (int64_t) sqrt((double) tmp);
                    v = (int16_t) sqrt(v);
                }
                else {
                    //jak nie * to +
                    res[k]='+';
                    k++;
                    v/=2;
                }

                if (z==0) {
                    if (v==1) break;
                }
                else{
                    if (tmp==2 && v==1) break;
                }
            }

            printf("/+");
            k--;
            while (k>=0){
                printf("%c", res[k]);
                k--;
            }

            return 0;   
        }

        z--;
    }

    printf("NO");
    return 0;
}