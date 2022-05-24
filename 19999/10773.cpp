#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    stack<int> s;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        if (k == 0)
            s.pop();
        else
            s.push(k);
    }
    int sum = 0;
    while(s.size()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
}