#include <stdio.h>
int findSum(int n, int T[n][n], int b, int w, int k);

int main(){
    int n,k,o;
    int b = 3, l=0;
    scanf("%d %d", &n,&k);
    int T[n][n];

    o = 2;
    while(n-o>0){
        l+=(n-o)*(n-o); //oblicz max liczbe kwadratow
        o+=2;
    }

    int t[l][2];
    l=0;

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &T[i][j]);
        }
    }

    
    while(b<=n){
        o = b/2; //tyle musi byc miejsca od srodka w kazda strone
        for (int i=o; i<=n-1-o; i++){
            for(int j=o; j<=n-1-o; j++){
                if (k==findSum(n,T,b,i,j)){
                    t[l][0]=i;
                    t[l][1]=j;
                    l+=1;
                }
            }
        }
        b+=2;
    }

    printf("%d\n", l);

    for(int i=0; i<l; i++) printf("%d %d\n", t[i][0], t[i][1]);

    return 0;
}

int findSum(int n, int T[n][n], int b, int w, int k) {
    int s = 0;
    int x=b/2;
    for (int i=0; i<b; i++) {
        s += T[w-x][k-x+i]; //gora
        s += T[w+x][k-x+i]; //dol
    }

    for (int i=1; i<b-1; i++){
        s += T[w-x+i][k-x]; //lewo
        s += T[w-x+i][k+x]; //prawo
    }

    return s;
}