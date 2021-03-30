#include<stdio.h>
#define N 100

int maxVal10(int b, int m);
int power(int a, int pow);
int checkIt(int b, int number, int m);

int main(){
    int m, b, nk, np, f=0;

    scanf("%d %d", &m, &b);
    nk = maxVal10(b,m); //max value in base=10
    np = power(b,m-1); //min value in base=10
    for(; np<=nk; np++){
        f += checkIt(b,np,m);
    }
    
    if(f==0) printf("NO");
    return 0;
}

int maxVal10(int b, int m){
    int valIn10=0;
    for(int i = 0; i < m; i++){
        valIn10 += power(b-1,m);
    }
    return valIn10;
}

int power(int a, int pow){
    int result=1;
    for(int i=0; i<pow; i++){
        result *= a;
    }
    return result;
}

int checkIt(int b, int number, int m){
    char numInB[m+1];
    int digit, tmp = number, calculate = 0;

    numInB[m]='\0';
    for(int i = m - 1; i>=0; i--){
        digit = tmp%b;
        calculate += power(digit, m);
        if(calculate > number) return 0;
        
        if(digit<10) numInB[i] = digit + '0';
        else numInB[i] = digit%10 + 'A';
        
        tmp /= b;
    }

    if(calculate == number){
        printf("%s ", numInB);
        return 1;
    }

    return 0;
}
