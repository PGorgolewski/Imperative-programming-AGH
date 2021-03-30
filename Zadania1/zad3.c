#include <stdio.h>

int main(){
    int a = 0, b = 1, res = 0;
    int n;

    scanf("%d", &n);

    while(res < n) {
        b = a + b;
        a = b - a;

        res = a*b;
    };

    if(res == n) {
        printf("YES");
    }
    else {
        printf("NO");
    };
};