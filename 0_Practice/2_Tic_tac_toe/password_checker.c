#include <stdio.h>  //标准输入输出：printf/fgets等函数
#include <string.h> //字符串处理：strlen函数
#include <ctype.h>  //字符处理：isupper/islower/isdigit等判断函数
#define MAX_LENGTH 64
#define MIN_LENGTH 8

int evaluate_password(const char *password)
{
    int length = strlen(password);

    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;
    int has_special = 0;

    // 定义特殊符号集合（34个常见的符号）
    const char *specials = "!@#$%^&*()-_=+[]{}|\\;:'\",<>./?";

    if (length < MIN_LENGTH)
        return 0;

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (islower(password[i]))
            has_lower = 1;
        else if (isupper(password[i]))
            has_upper = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
        else if (strchr(specials, password[i]))
            has_special = 1;
    }

    int score = 0;
    score += has_lower + has_upper; // 大写小写各1分
    score += has_digit;
    score += has_special * 2;

    if (length >= 12)
        score += 1;
    if (length >= 16)
        score += 2;

    // 长度>16，并且包含大小写，特殊字符，数字的组合 得2分
    if (has_special && has_lower && has_upper && has_special)
        score += 3;

    return score;
}

void print_stars(int score)
{
    int stars = 0;
    printf("密码强度：");
    if (score >= 11)
        stars = 5;
    else if (score >= 9)
        stars = 4;
    else if (score >= 7)
        stars = 3;
    else if (score >= 4)
        stars = 2;
    else if (score >= 1)
        stars = 1;
    else
        stars = 0;

    for (int i = 0; i < stars; i++)
        printf("★");
    for (int i = stars; i < 5; i++)
        printf("☆");

    char *advice[] = {
        "立即更换！建议长度≥12字符+四种字符组合",
        "需加强：尝试混合大小写与特殊符号",
        "合格基础：可添加生僻词组合",
        "良好：定期更换并启用双因素认证",
        "优秀：符合企业级安全标准"};
    printf("\n");
    printf("安全建议：%s\n", advice[stars]);
}

int main()
{
    char password[MAX_LENGTH + 1];

    printf("====== 密码强度检测器 =====\n");
    printf("请输入待检测的密码(最多%d字符): (回车键结束) > ", MAX_LENGTH);

    if (fgets(password, sizeof(password), stdin))
    {
        password[strcspn(password, "\n")] = '\0';

        int score = evaluate_password(password);
        print_stars(score);
    }
    else
        printf("输入错误！\n");

    return 0;
}