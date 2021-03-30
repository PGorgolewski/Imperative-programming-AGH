#include<stdio.h>
#include<stdlib.h>

int comp (const void * elem1, const void * elem2);

int main(){
    unsigned int n;
    int k,t;
    int l=0, i=0;

    scanf("%d %d", &n,&k);

    int* tab = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &tab[i]);

    qsort(tab, n, sizeof(*tab), comp); //tablica posortowana rosnąco

    if(n!=1){
        while(i<n){
            t = i;
            while(t<n-1 && tab[t+1]==tab[t]) t++;

            if (t+1 < n && tab[t+1]-tab[i] <= k) l += t - i + 1;
            else if (i-1 >= 0 && tab[i]-tab[i-1] <= k) l += t - i + 1;

            i = t + 1;
        }
    }
    
    printf("%d",l);
    return 0;
}

int comp (const void * elem1, const void * elem2) {
    return *(int*)elem1 - *(int*)elem2;
}

