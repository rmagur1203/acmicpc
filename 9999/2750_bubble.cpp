#include <iostream>

int main()
{
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int r = 0; r < N; r++)
    {
        for (int k = 0; k < N - r - 1; k++)
        {
            if (arr[k] > arr[k+1]){
                int tmp = arr[k+1];
                arr[k+1] = arr[k];
                arr[k] = tmp;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
    system("pause");
}