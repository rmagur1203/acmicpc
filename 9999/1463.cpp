#include <iostream>
#include <algorithm>
#include <memory.h>

/* 다른 사람이 DP 로 짠 블로그 보고 이해해왔다!
 * 배열을 만들어서 index 값의 수를 만드는데 가장 적게 드는 횟수를 낮은 index 부터 채워간다
 * n + 1 번째의 수 일때
 * n-1 과 n/2 와 n/3 번째 배열의 값들을 비교해서 가장 작은 값이
 * 최소한의 움직임으로 구현할 수 있다!
 */

class DP
{
private:
    int n;
    int *arr;

public:
    void init(int n)
    {
        this->n = n;
        this->arr = (int *)malloc(sizeof(int) * (n + 1));
        memset(this->arr, 0, sizeof(int) * (n + 1));
    }

    int run()
    {
        arr[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] + 1;
            if (i % 2 == 0)
                arr[i] = std::min(arr[i], arr[i / 2] + 1);
            if (i % 3 == 0)
                arr[i] = std::min(arr[i], arr[i / 3] + 1);
        }
        return arr[n];
    }
};

int main()
{
    int n;
    DP dp;
    scanf("%d", &n);
    dp.init(n);
    printf("%d", dp.run());
    system("pause");
}

/*
실패한 코드!
struct result
{
    bool can_do = true;
    int count = 0;
};

struct result factorization(int value);

int main()
{
    int x, count = 0;
    scanf("%d", &x);
    while (x != 1)
    {
        struct result res = factorization(x);
        if (res.can_do)
        {
            count += res.count;
            break;
        }
        else
            x--;
        count++;
    }
    printf("%d", count);
    system("pause");
}

struct result factorization(int val)
{
    struct result result;
    while (val != 1)
    {
        if (val % 3 == 0)
        {
            val /= 3;
            result.count++;
        }
        else if (val % 2 == 0)
        {
            val /= 2;
            result.count++;
        }
        else
        {
            result.can_do = false;
            return result;
        }
    }
    return result;
}
*/