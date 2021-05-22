#include <stdio.h>
#define N 51

void change(int n, char res[n+1], char s[n+1], int o, int p);

int main(){
    char s[N];
    int firsts[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int n=0, k=0, p;

    scanf("%s", s);
    while(s[n] != '\0'){
        n+=1;
    }

    char res[n+1], res2[n+1];
    res[n] = '\0';
    res2[n] = '\0';

    p=2;
    for (int i=0; i<n; i++){
        res[i] = s[(0+p*i)%n];
    }

    while(firsts[k] != '\0' && firsts[k]<n){
        p = firsts[k];
        for (int o=0; o<n; o++){
            for (int i=0; i<n; i++){
                res2[i] = s[(o+p*i)%n];
                if (res2[i] < res[i]) {
                    change(n, res,s,o,p);
                    break;
                }
                else if (res2[i] > res[i]) break;
                
            }
        }
        k++;
    }

    printf("%s", res);

    return 0;
}


void change(int n, char res[n+1], char s[n+1], int o, int p){
    for (int i=0; i<n; i++){
        res[i] = s[(o+p*i)%n];
    }
}