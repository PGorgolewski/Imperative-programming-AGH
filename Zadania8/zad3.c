#include <stdio.h>
#define N 51

int main(){
    char s[N], res[N], b;
    int i = 0, k=0, z;

    scanf("%s", s);

    while(1){
        b = s[k];
        z = k+1;

        if (b == '\0'){
            res[i] = '\0';
            break;
        }

        while(s[z] != '\0'){
            if (b < s[z]){
                b = s[z];
                k = z;
            }
            z++;
        }

        res[i] = b;
        k++;
        i++;
    }

    printf("%s", res);

    return 0;
}