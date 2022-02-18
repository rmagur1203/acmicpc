#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--){
        stack<int> st;
        string s;
        bool br = false;
        cin >> s;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(')
                st.push(1);
            else if (s[i] == ')'){
                if (st.size() <= 0){
                    cout << "NO\n";
                    br = true;
                    break;
                }
                st.pop();
            }
        }
        if (st.size() >= 1)
            cout << "NO\n";
        else if (!br)
            cout << "YES\n";
    }
}