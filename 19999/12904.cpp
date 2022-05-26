#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    char S[1001];
    char T[1001];
    cin >> S;
    cin >> T;

    vector<char> s, t;
    for (int i = 0; S[i] != '\0'; i++)
        s.push_back(S[i]);
    for (int i = 0; T[i] != '\0'; i++)
        t.push_back(T[i]);
    while (s.size() < t.size()){
        char back = t.back();
        t.pop_back();
        if (back == 'B'){
            reverse(t.begin(), t.end());
        }
    }
    cout << (s == t);
}