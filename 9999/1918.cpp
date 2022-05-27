#include <bits/stdc++.h>

using namespace std;

char srank[128];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    srank['+'] = 1;
    srank['-'] = 1;
    srank['*'] = 2;
    srank['/'] = 2;

    string str;
    cin >> str;
    stack<char> s;
    for (int i = 0; i < str.length(); i++){
        switch (str[i]) {
            case '(':
                s.push(str[i]);
                continue;
            case ')':
                while(!s.empty()){
                    if (s.top() == '(') break;
                    cout << s.top();
                    s.pop();
                }
                s.pop();
                continue;
            case '+':
            case '-':
            case '*':
            case '/':
                while(!s.empty()){
                    if (srank[s.top()] < srank[str[i]]) break;
                    cout << s.top();
                    s.pop();
                }
                s.push(str[i]);
                continue;
        }
        cout << str[i];
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}