#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 200000 //bo jeszcze sztuczne wierzcholki

double distance(double x1,double x2,double y1,double y2){
    double q = x1-x2, w=y1-y2;

    q*=q;
    w*=w;

    return sqrt(q+w);
}

int minusID(int number, int len){
    if (number >= 0) return number;
    return number+len;
}

int main(){
    int t, n, k, counter;
    double x1,x2,y1,y2, tmp1, tmp2;
    scanf("%d", &t);
    
    int *K = (int *)calloc((unsigned int) t, sizeof(int)); //tu bedzie ile mamy wierzcholkow dla danej figury

    double ***W = (double ***)calloc((unsigned int) t, sizeof(double **));

    for (int i=0; i<t; i++){
        scanf("%d", &n);
        K[i]=2*n;
        
        W[i] = (double **)calloc((unsigned int) K[i], sizeof(double *));
        for (int j=0; j<K[i]; j++){
            W[i][j] = (double *)calloc(2,sizeof(double));
        }
        
        scanf("%lf %lf", &W[i][0][0], &W[i][0][1]);
        
        x2=W[i][0][0];
        y2=W[i][0][1];
        k=1;
        while(k < (K[i]-1) ){ //sztuczny wierzcholek pomiedzy pierwszym a ostatnim trzeba oddzielnie
            scanf("%lf %lf", &x1, &y1);

            W[i][k][0] = ((x1+x2)/2);
            W[i][k][1] = ((y1+y2)/2);

            k++;

            W[i][k][0] = x1;
            W[i][k][1] = y1;

            x2 = x1;
            y2=y1;
            k++;
        }

        W[i][K[i]-1][0] = ((W[i][0][0]+x1)/2);
        W[i][K[i]-1][1] = ((W[i][0][1]+y1)/2);
    }

    for (int i=0; i<t; i++){
        counter = 0;
        n=K[i]/2;
        for (int a=0; a<n; a++){ //jest tylko n-potencjalnych
            k=1; // jezeli zostanie 1 to znaczy ze istnieje 
            for(int w=1; w<n; w++){
                int leftID = minusID(a-w,K[i]);
                tmp1 = distance(W[i][a][0], W[i][a+w][0], W[i][a][1], W[i][a+w][1]);
                tmp2 = distance(W[i][a][0], W[i][leftID][0], W[i][a][1], W[i][leftID][1]);
                if (tmp1 != tmp2){
                    k=0;
                    break;
                }

                tmp1 = distance(W[i][a+n][0], W[i][a+w][0], W[i][a+n][1], W[i][a+w][1]);
                tmp2 = distance(W[i][a+n][0], W[i][leftID][0], W[i][a+n][1], W[i][leftID][1]);

                if (tmp1 != tmp2){
                    k=0;
                    break;
                }
            }

            if (k==1) counter+=1;
        }
        printf("%d\n", counter);
    }

    return 0;
}
