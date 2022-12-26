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

long long int calcB(long long int k) {
    long long int cnt = 0;
    while (k > 0) {
        cnt += k & 1;
        k = k >> 1;
    }
    return cnt;
}

long long int calcM(long long int k) {
    long long int cnt = 0;
    while (k > 0) {
        cnt += cve[k % 16];
        k = k / 16;
    }
    return cnt;
}

long long int kcounter(long long int k) {
    long long int cnt = 0;
    while (k > 0) {
        cnt += cve[k % 16];
        k = k / 16;
    }
    return cnt;
}

/**
 * k - 4 ~ k 까지의 1의 개수의 근사치를 구한다.
*/
long long int sumM(long long int k) {
    long long int v = k;
    long long int cnt = 4;
    while (v > 0) {
        cnt += cve[(v / 4) % 16] * 4;
        v = v / 16;
    }
    return cnt;
}
long long int sumP(long long int k) {
    long long int v = k / 4;
    long long int cnt = 0;
    while (v > 0) {
        cnt += cve[v % 16];
        v = v / 16;
    }
    return - (RsumC[k % 4] + (3 - (k % 4)) * cnt);
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

char* toBinary(int n) {
    char* binary = new char[33];
    for (int i = 0; i < 32; i++) {
        binary[i] = '0';
    }
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2 + '0';
        n = n / 2;
        i++;
    }
    return binary;
}

int calcRadix(long long int k) {
    long long int radix = 1;
    while (k > 0) {
        radix *= 4;
        k = k / 16;
    }
    return radix;
}

// long long int sumMR(long long int k, int radix) {
//     long long int v = k / radix;
//     long long int cnt = 4;
//     while (v > 0) {
//         cnt += cve[(v / 4) % 16] * 4;
//         v = v / 16;
//     }
//     return cnt;
// }
long long int sumMR(long long int k, int radix) {
    k = k / radix * radix + 1;
    long long int root = rootOf4(radix);
    long long int cnt = root;
    // cout << "k: " << k << endl;
    while (k > 0) {
        cnt += cve[(k / radix) % 16];
        k = k / 16;
    }
    // cout << "sumMR: " << cnt << endl;
    return cnt * radix;
}
long long int sumMRE(long long int k, int radix) {
    long long int root = rootOf4(radix);
    long long int cnt = 1;
    while (k > 0) {
        cnt += (cve[(k / radix) % 16]);
        k = k / (radix * 4);
    }
    return cnt * radix;
}
long long int recCalc(long long int sI, long long int eI, long long int radix) {
    /**
     * sI - eI 까지의 1의 개수를 구한다.
     * 배열은 sI가 0으로 시작한다고 가정한다.
     * start는 radix 기준 시작 인덱스
    */
    if (radix == 1) {
        return sumMP(eI);
    }
    long long int end = (eI - sI) / radix; // eI = 1, sI = 0, radix = 1
    long long int sum = 0;
    // cout << "sI: " << sI << ", eI: " << eI << ", radix: " << radix << ", end: " << end << endl;
    for (int i = 1; i <= end; i++) {
        // cout << "i: " << i << ", radix: " << radix << ", sI: " << sI << ", V: " << (i - 1) * radix + sI << ", sumMR: " << sumMR((i - 1) * radix + sI, radix) << endl;
        sum += sumMR((i - 1) * radix + sI, radix);
        // cout << "sum[" << i << "] = " << sum << endl;
    }
    // long long int sV = 
    long long int eV = sum + recCalc(eI / radix * radix, eI, radix / 4);

    // cout << "ev " << eV << endl;
    
    return eV;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    // for (int i = 0; i <= 16; i++) {
    //     cout << i << ": " << sumMR(i, 4) << endl;
    // }

    cin >> A >> B;
    
    // long long int testSum = 0;
    // cout << "B: " << B << endl;
    int initRadix = calcRadix(B);
    // cout << "RADIX: " << initRadix << endl;

    long long int* sum = new long long int[B / initRadix + 1];
    sum[0] = sumMR(0, initRadix);
    // cout << "sum[0] = " << sum[0] << endl;
    for (int i = 1; i <= B / initRadix; i++) {
        sum[i] = sum[i-1] + sumMR(i * initRadix, initRadix);
        // cout << "sum[" << i << "] = " << sum[i] << endl;
    }
    // for (int i = 0; i < 320; i++) {
    //     testSum += calcB(i);
    // }
    // cout << "sumcheck: " << testSum << endl;
    long long int sumA = A / initRadix > 0 ? sum[A / initRadix - 1] : 0;
    long long int sumB = B / initRadix > 0 ? sum[B / initRadix - 1] : 0;
    delete[] sum;

    // cout << "A\tB" << endl;
    // cout << A / initRadix << "\t" << B / initRadix << endl;
    // cout << sumA << "\t" << sumB << endl;

    sumA = sumA + recCalc(A / initRadix * initRadix, A - 1, initRadix / 4);
    sumB = sumB + recCalc(B / initRadix * initRadix, B, initRadix / 4);

    // cout << sumA << "\t" << sumB << endl;
    cout << sumB - sumA << endl;

    // testSum = 0;
    // for (int i = A; i <= B; i++) {
    //     testSum += calcB(i);
    // }
    // cout << testSum << endl;

    // for (int i = 0; i <= B / 4; i++) {
    //     sum[i] = sum[i-1] + sumMP(i * 4 + 3);
    //     // cout << i * 4 << "\t" << sum[i] << endl;
    // }

    // long long int sumA = sumMP(A-1);
    // if ((A / 4) - 1 >= 0) {
    //     sumA += sum[(A / 4) - 1];
    // }

    // long long int sumB = sumMP(B);
    // if ((B / 4) - 1 >= 0) {
    //     sumB += sum[(B / 4) - 1];
    // }

    // cout << sumB - sumA << endl;

    // cout << sum[B] - sum[A-1] << endl;

    // int start = calc(A);
    // int end = calc(B);
    // int diff = B - A;

    // long long ans = 0;
    // ans += (long long)start * (diff + 1);
    // ans += (long long)end * (diff + 1) * diff / 2;
    // cout << ans << endl;

    // int sum[10000];
    // cout << "i\tbinary\t\t\t\t\tm\tsum\tsumM+P\tsumM\tsumP\tsumMP" << endl;
    // for (int i = 0; i < 1e2; i++) {
    //     // long long int b = calcB(i);
    //     long long int m = calcM(i);
    //     long long int s = sumM(i);
    //     long long int p = sumP(i);
    //     long long int mp = sumMP(i);
    //     // if (i % ((int)1e4) == 0)
    //     //     cout << b << endl;
    //     // if (b != m) {
    //     //     cout << i << "\t" << toBinary(i) << "\t" << b << "\t" << m << endl;
    //     // }
    //     sum[i] = sum[i-1] + m;
    //     cout << i << "\t";
    //     cout << toBinary(i) << "\t";
    //     cout << m << "\t";
    //     cout << sum[i] - sum[max(0, (i/4)*4)-1] << "\t";
    //     cout << s + p << "\t";
    //     cout << s << "\t";
    //     cout << p << "\t";
    //     cout << mp << endl;
    //     if (i % 4 == 3)
    //         cout << endl;
    // }
}