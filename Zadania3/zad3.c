#include <stdio.h>

int first(int n);

int main(){
    int l,u,k,num,tmp;

    scanf("%d %d %d", &l,&u,&k);

    for(int i=l; i<=u;i++){
        num = i;
        if(first(num)==0) continue;

        while(num!=1 && num!=4){ //Petla zawsze sie wykona bo 1 i 4 nie są pierwsze
            tmp = 0;
            while(num>0){
                tmp += (num%10)*(num%10);
                num /= 10;
            }
            num = tmp;
        }
        if(num == 1){
            k -= 1;
            if(k == 0){
                printf("%d", i);
                break;
            }
        }
    }

    if(k != 0) printf("-1");
    return 0;
}

int first(int n) { //zwraca 0 gdy nie jest pierwsza, 1 gdy jest
    if (n == 2 || n == 3) {
        return 1;
    };

    if (n<=1 || n%2 == 0 || n%3 == 0) {
        return 0;
    };


    for(int j=5; j*j<=n; j+=6){
            if (n%j == 0 || n%(j+2) == 0){
            return 0;
            };
    };

    return 1;
};
