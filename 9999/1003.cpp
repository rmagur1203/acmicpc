#include <iostream>
#include <windows.h>

int z, o;

int f(int i){
    if (i == 0){
        z += 1;
    }
    else if (i == 1){
        o += 1;
    }
    else
        f(i - 1) + f(i - 2);
}

int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int j;
        scanf("%d", &j);
        z = 0;o = 0;
    }
    system("pause");
    return 0;
}