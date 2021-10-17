#include <stdio.h>
#include <windows.h>

int main()
{
    int a = 10;
    int *b = &a;
    int **c = &b;
    int ***d = &c;
    printf("%p %p %p %p\n", &a, b, *c, **d);
    printf("%d %d %d %d", a, *b, **c, ***d);

    system("pause");
    return 0;
}