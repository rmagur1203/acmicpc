#include <cstdio>

/* 규칙
 * k개의 원판을 C 이동
 * k-1의 탑을 B로 이동
 * 맨 아래 원판을 C로 이동
 * k-1의 탑을 C로 이동
 */

int hanoi_move(int n)
{
    if (n == 1)
        return 1;
    else
        return 2 * hanoi_move(n - 1) + 1;
}
void hanoi(int n, int from, int via, int to)
{
    if (n == 1)
        printf("%d %d\n", from, to);
    else
    {
        hanoi(n - 1, from, to, via);
        printf("%d %d\n", from, to);
        hanoi(n - 1, via, from, to);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", hanoi_move(n));
    hanoi(n, 1, 2, 3);
    return 0;
}