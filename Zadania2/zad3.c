#include<stdio.h>
#define N 100

int recur(int tab[], int sum1, int sum2, int i, int n);

int main(){
    int tab[N], n, w, f;

    scanf("%d %d", &n, &w);
    for(int i=0; i<n;i++){
        scanf("%d", &tab[i]);
    }

    f = recur(tab, 0, w, 0, n);
    if (f>0) printf("YES");
    else printf("NO");

    return 0;
}

int recur(int tab[], int sum1, int sum2, int i, int n){
    int a1,a2;
    
    if (sum1==sum2) return 1;
    if(n==i) return 0;
        
    a1 = recur(tab, sum1 + tab[i], sum2, i+1, n);
    a2 = recur(tab, sum1, sum2 + tab[i], i+1, n);

    return a1+a2;

}
