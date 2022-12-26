#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <cmath>

using namespace std;

/**
 * 9527. 1의 개수 세기
 * https://www.acmicpc.net/problem/9527
 * 
 * 1. A와 B를 입력받는다.
 * 2. A와 B 사이의 모든 수를 2진수로 변환한다.
 * 3. 2진수로 변환한 수에서 1의 개수를 센다.
 * 4. 1의 개수를 모두 더한다.
 * 
 * 분류: 비트마스킹
*/

int cv[4] = { 0, 1, 1, 2 };
int cve[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

int sumC[4] = { 0, 1, 2, 4 };
int RsumC[4] = { 4, 3, 2, 0 };

long long int A, B;

int rootOf4(long long int k) {
    int cnt = 0;
    while (k > 1) {
        cnt += 1;
        k = k / 4;
    }
    return cnt;
}

long long int sumMP(long long int k) {
    long long int v = k / 4;
    long long int cnt = 0;
    while (v > 0) {
        cnt += cve[v % 16];
        v = v / 16;
    }
    long long int M = 4 + cnt * 4;
    long long int P = (RsumC[k % 4] + (3 - (k % 4)) * cnt);
    return M - P;
}

long long int calcRadix(long long int k) {
    long long int radix = 1;
    while (k > 0) {
        radix *= 4;
        k = k / 4;
    }
    return radix;
}
long long int sumMR(long long int k, long long int radix) {
    k = k / radix * radix + 1;
    long long int root = rootOf4(radix);
    long long int cnt = root;
    while (k > 0) {
        cnt += cve[(k / radix) % 16];
        k = k / 16;
    }
    return cnt * radix;
}
long long int recCalc(long long int sI, long long int eI, long long int radix) {
    if (radix <= 1) {
        return sumMP(eI);
    }
    long long int end = (eI - sI) / radix;
    long long int sum = 0;
    for (long long int i = 1; i <= end; i++) {
        sum += sumMR((i - 1) * radix + sI, radix);
    }
    long long int eV = sum + recCalc(eI / radix * radix, eI, radix / 4);
    
    return eV;
}

long long int calcB(long long int k) {
    long long int cnt = 0;
    while (k > 0) {
        cnt += k & 1;
        k = k >> 1;
    }
    return cnt;
}

long long int answer(long long int k) {
    long long int testSum = 0;
    for (int i = 0; i <= k; i++) {
        testSum += calcB(i);
    }
    return testSum;
}

long long int solve(long long int k) {
    long long int A = 1;
    long long int B = k;
    long long int initRadix = calcRadix(B);

    long long int* sum = new long long int[B / initRadix + 1];
    sum[0] = sumMR(0, initRadix);
    for (long long int i = 1; i <= B / initRadix; i++) {
        sum[i] = sum[i-1] + sumMR(i * initRadix, initRadix);
    }
    long long int sumA = A / initRadix > 0 ? sum[A / initRadix - 1] : 0;
    long long int sumB = B / initRadix > 0 ? sum[B / initRadix - 1] : 0;
    delete[] sum;
    sumA = sumA + recCalc(A / initRadix * initRadix, A - 1, initRadix / 4);
    sumB = sumB + recCalc(B / initRadix * initRadix, B, initRadix / 4);
    return sumB - sumA;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> A >> B;

    for (long long int i = 1; i <= 1e16; i++) {
        if (i % 100000 == 0)
            break;
        if (answer(i) != solve(i)){
            return 0;
        }
    }
}