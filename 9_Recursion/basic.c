#include <stdio.h>
#include <stdlib.h>

// 计算1~n的和。
int getSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = i + sum;
    }
    return sum;
}

int getSumRecur(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
        return n + getSumRecur(n - 1);
}

int fibonacci(int n)
{
    int last1 = 1;
    int last2 = 1;
    int result = 1;
    for (int i = 3; i <= n; i++)
    {
        result = last1 + last2;
        last1 = last2;
        last2 = result;
    }
    return result;
}

int getFibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
        return getFibonacci(n - 1) + getFibonacci(n - 2);
}

int main()
{
    // printf("%d\n", getSum(20));
    // printf("%d\n", getSumRecur(20));

    printf("%d\n", fibonacci(5));
    printf("%d\n", getFibonacci(5));

    return 0;
}