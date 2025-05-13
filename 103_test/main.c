#include <stdio.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("时间戳: %lld\n", (long long)now);
    printf("本地时间: %04d-%02d-%02d %02d:%02d:%02d\n",
           t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
           t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}