#include <stdio.h>

// 定义了Student结构体
struct Student
{
    int ID;
    char name[20];
    float score;
};

int main()
{
    struct Student stu = {1, "张三", 75.4};
    printf("%d %s %.2f", stu.ID, stu.name, stu.score);
    return 0;
}