#include<stdio.h>
#include<stdlib.h>

int comp (const void * elem1, const void * elem2);

int main() {
    int n,k,sum,z,tmp;

    scanf("%d %d", &n,&k);

    int tab[n];
    for(int i=0; i<n;i++){
        scanf("%d", &tab[i]);
    }

    qsort(tab, sizeof(tab)/ sizeof(*tab), sizeof(*tab), comp); //tablica posortowana malejaco

    for(int i=0;i<k;i++){
        tab[0] = tab[0]/2;
        z = 1;
        tmp = tab[0];
        while(z < n-1 && tab[z] > tmp){
            tab[z-1] = tab[z];
            z+=1;
        }
        tab[z-1]=tmp;
    }

    sum = 0;
    for(int i=0; i<n; i++){
        sum += tab[i];
    }

    printf("%d",sum);
    return 0;
}

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f < s) return  1;
    if (f > s) return -1;
    return 0;
}