#include <stdio.h>

int main(){
    int N, x1, x2, y1, y2;
    int s=0;
    int t[200][200];

    for (int i=0; i<200; i++){
        for (int j=0; j<200; j++){
            t[i][j] = 0;
        }
    }
    scanf("%d", &N);

    for (int i=0; i<N; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1 += 100;
        x2 += 100;
        y1 += 100;
        y2 += 100;

        for (int x=0; x2>x1+x; x++){
            for (int y=0; y2>y1+y; y++){
                t[x1+x][y1+y] += 1;
            }
        }
    }

    for (int i=0; i<200; i++){
        for (int j=0; j<200; j++){
            if (t[i][j] % 2 == 1) s+=1;
        }
    }

    printf("%d", s);

    return 0;
}