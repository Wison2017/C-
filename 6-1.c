6-1 使用函数求素数和 （20 分)
本题要求实现一个判断素数的简单函数、以及利用该函数计算给定区间内素数和的函数。

素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。

函数接口定义：
int prime( int p );
int PrimeSum( int m, int n );
其中函数prime当用户传入参数p为素数时返回1，否则返回0；函数PrimeSum返回区间[m, n]内所有素数的和。题目保证用户传入的参数m≤n。

#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}
int prime(int p){
    int i;
    if (p <= 3)
        return p > 1;
    if (p % 6 != 1 && p % 6 != 5)
        return 0;
    for (i = 5; i <= sqrt(p); i+=6){
        if (p % i == 0 || p % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int PrimeSum(int m, int n){
    int p;
    int sum = 0;
    for (p = m; p <= n; p++){
        if (prime(p) == 1){
            sum += p;
        }
    }
    return sum;
}