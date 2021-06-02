#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define N 100000
//moj pomysl i nie wiadomo czemu daje zly wynik w jednym tescie

void threeFirst(int n, int64_t red[n], int r[3] ){ //pierw robiona dla red wiec tak zostalo
    for (int i=0; i<3; i++){
        if (red[0]>red[1]){
            if (red[2] > red[0]){
                r[0] = 2;
                r[1] = 0;
                r[2] = 1;
            }
            else{
                r[0]=0;
                if (red[2]>red[1]){
                    r[1]=2;
                    r[2]=1;
                }
                else{
                    r[1]=1;
                    r[2]=2;
                }
            }
        }
        else{
            if (red[2] > red[1]){
                r[0] = 2;
                r[1] = 1;
                r[2] = 0;
            }
            else{
                r[0]=1;
                if (red[0]>red[2]){
                    r[1]=0;
                    r[2]=2;
                }
                else{
                    r[1]=2;
                    r[2]=0;
                }
            }
        }
    }

    return;
}

void check(int n, int64_t color[n], int c[3], int i){
    int k=2;
    int64_t tmp = color[i];

    if (tmp > color[c[k]]){
        c[k] = i;
        k--;
    }
    else return;

    while(tmp>color[c[k]] && k>=0){
        c[k+1]=c[k];
        c[k]=i;
        k--;
    }

    return;
}
int main(){
    int n;
    int64_t col=0, tmp, rsum=0, bsum=0, gsum=0, m=0;
    int b[3], g[3], r[3], res[3];

    scanf("%d", &n);

    int64_t *red = (int64_t *)calloc((unsigned int) n, sizeof(int64_t));
    int64_t *blue = (int64_t *)calloc((unsigned int) n, sizeof(int64_t));
    int64_t *green = (int64_t *)calloc((unsigned int) n, sizeof(int64_t));

    for (int i = 0; i<n; i++) scanf("%"SCNd64, &red[i]);
    for (int i = 0; i<n; i++) scanf("%"SCNd64, &green[i]);
    for (int i = 0; i<n; i++) scanf("%"SCNd64, &blue[i]); 
    for (int i=0; i<n; i++){
        rsum += red[i];
        gsum += green[i];
        bsum += blue[i];
    }

    if (n<3){
        for (int i=0; i<n; i++){
            if (red[i] != 0){
                col++; 
                break;
            } 
        }

        for (int i=0; i<n; i++){
            if (blue[i] != 0){
                col++;
                break;
            }
        }

        for (int i=0; i<n; i++){
            if (green[i] != 0){
                col++;
                break;
            }        
        }

        if (col > n){
            printf("-1");
            return 0;
        }

        if (col == 1) printf("0");
        else{
            // n=2, col=2
            if (gsum==0){
                col = blue[0] + red[1];
                if (col > blue[1] + red[0]) col=blue[1] + red[0];
            }
            else if(bsum==0){
                col = green[0] + red[1];
                if (col > green[1] + red[0]) col=green[1] + red[0];
            }
            else{
                col = green[0] + blue[1];
                if (col > green[1] + blue[0]) col=green[1] + blue[0];
            }

            printf("%"PRId64, col);
        }
        return 0;
    }

    threeFirst(n,red,r);
    threeFirst(n,blue,b);
    threeFirst(n,green,g);

    for (int i=3; i<n; i++){
        check(n,red,r,i);
        check(n,blue,b,i);
        check(n,green,g,i);
    }

    //res to r,b,g
    for (int re=0; re<3; re++){
        for (int bl=0; bl<3; bl++){
            for (int gr=0; gr<3; gr++){
                if (r[re]!=b[bl] && r[re]!=g[gr] && b[bl]!=g[gr]){
                    tmp = red[r[re]]+blue[b[bl]]+green[g[gr]];
                    if (tmp>m) {
                        m = tmp;
                        res[0]=r[re];
                        res[1]=b[bl];
                        res[2]=g[gr];
                    }
                }
            }
        }
    }

    m = rsum+bsum+gsum;
    m -= red[res[0]];
    m -= blue[res[1]];
    m -= green[res[2]];
    for(int i=0; i<n; i++){
        if (i==res[0] || i==res[1] || i==res[2]) continue;

        if (red[i] >= blue[i] && red[i] >= green[i]) m-=red[i];
        else if(green[i]>=blue[i] && green[i]>=red[i]) m-=green[i];
        else m-=blue[i];
    }
    
    printf("%"PRId64, m);
}