#include <stdio.h>
#define N 1000

int main() {
    int tab[N];
    int n, i, leftSum = 0, rightSum = 0;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &tab[i]);
        rightSum += tab[i];
    }

    i=0;
    while(1){
        rightSum -= tab[i];

        if(rightSum == leftSum) {
            printf("%d", i);
            break;
        }

        leftSum += tab[i];
        i++;
    }

    return 0;
}