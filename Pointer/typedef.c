#include <stdio.h>
#include <string.h>

typedef struct book
{
    int ISBN;
    char book_name[20];
    double price;
} Book;
struct hero
{
    char name[20];
    int type;
    double life;
};

int main()
{
    Book b;
    b.ISBN = 123456;
    strcpy(b.book_name, "平凡的世界");
    b.price = 29.99;
    printf("ISBN:\%d\n", b.ISBN);
    printf("book_name:\%s\n", b.book_name);
    printf("price:\%6.2lf\n", b.price);
    return 0;
}