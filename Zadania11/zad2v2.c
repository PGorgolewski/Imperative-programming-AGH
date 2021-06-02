#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//pomysl kolegi, ktory przechodzi all testy

int min(int a, int b){
    return (a < b) * a + (a >= b) * b;
}

int findResult(int red[], int green[], int blue[], int n){
    int t[120][10];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 7; j++) {
            t[i][j] = 1 << 30;
        }
    }

    t[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 7; j++){
            t[i + 1][j | 1] = min(t[i + 1][j | 1], t[i][j] + green[i] + blue[i]);
            t[i + 1][j | 2] = min(t[i + 1][j | 2], t[i][j] + red[i] + blue[i]);
            t[i + 1][j | 4] = min(t[i + 1][j | 4], t[i][j] + red[i] + green[i]);
        }
    }

    int j = 0;
    for (int i = 0; i < n; i++){
        if (red[i]) j |= 1;
        if (green[i]) j |= 2;
        if (blue[i]) j |= 4;
    }

    if (t[n][j] >= (1<<30)) t[n][j] = -1;

    return t[n][j];  
}


int main()
{
    int n;
    scanf("%d",&n);
    
    int *red = (int*)calloc((unsigned int) n, sizeof(int));
    int *green =(int*)calloc((unsigned int) n, sizeof(int));
    int *blue = (int*)calloc((unsigned int) n, sizeof(int));

    for (int i=0; i<n; i++) scanf("%d",&red[i]);
    for (int i=0; i<n; i++) scanf("%d",&green[i]);
    for (int i=0; i<n; i++) scanf("%d",&blue[i]);

    printf("%d", findResult(red, green, blue, n));

    return 0;
}