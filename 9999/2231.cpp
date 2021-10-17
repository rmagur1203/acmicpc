#include <cstdio>


bool check(int k, int n){
    int v = k;
    while(k){
        v += k % 10;
        k /= 10;
    }
    return v == n;
}
int decomp(int n){
    for (int i = 1; i <= n; i++){
        if(check(i, n) == true)
            return i;
    }
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", decomp(n));
}