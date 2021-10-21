#include <iostream>
#include <deque>

using namespace std;

deque<int> stack;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int k;
            cin >> k;
            stack.push_back(k);
        }
        if (command == "pop")
        {
            if (stack.empty())
                cout << -1 << "\n";
            else
            {
                cout << stack.back() << "\n";
                stack.pop_back();
            }
        }
        if (command == "size")
        {
            cout << stack.size() << "\n";
        }
        if (command == "empty")
        {
            cout << stack.empty() << "\n";
        }
        if (command == "top")
        {
            if (stack.empty())
                cout << -1 << "\n";
            else
                cout << stack.back() << "\n";
        }
    }
}