#include "stdio.h"


unsigned long* to_binary(unsigned long result[], unsigned long num, int m)
{
    for (int i = 0; i < m; i++)
    {
        result[i] = num % 2;
        num /= 2;
    }
    for (int i = 0; i < m / 2; i++)
    {
        unsigned long temp = result[i];
        result[i] = result[m - 1 - i];
        result[m - 1 - i] = temp;
    }
    return result;
}


unsigned long to_decimal(unsigned long arr[], int n)
{
    unsigned long res = 0, pow_2 = 1;
    for (int i = n - 1; i >= 0 ; --i)
    {
        if (arr[i] == 1) res += pow_2;
        pow_2 *= 2;
    }
    return res;
}


int count_to_semi_something(unsigned long long num, int n)
{
    unsigned long long pow_2 = 1;
    unsigned long long max_num = 0;
    for (int i = 0; i < n; ++i)
    {
        max_num += pow_2;
        pow_2 *= 2;
    }

    unsigned long long curr_num = num;
    int how_many = 0;
    int checked[max_num + 1];
    for (int i = 0; i <max_num + 1 ; ++i)
    {
        checked[i] = 0;
    }
    while (curr_num <= max_num)
    {
        unsigned long bin_num[n];
        unsigned long * bin = to_binary(bin_num, curr_num, n);
        for (int i = 0; i < n; ++i)
        {
            bin[i] = (bin[i] + 1) % 2;
            unsigned long changed_num = to_decimal(bin, n);
            bin[i] = (bin[i] + 1) % 2;
            if (changed_num % num != 0  && checked[changed_num] == 0) how_many++;
            checked[changed_num] = 1;
        }
        curr_num += num;
    }
    return how_many;
}




int main()
{
    unsigned long num;
    int n;
    scanf("%d %lu", &n, &num);
    int res = count_to_semi_something(num, n);
    printf("%d", res);
    return 0;
}