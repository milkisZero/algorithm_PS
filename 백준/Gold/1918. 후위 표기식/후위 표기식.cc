#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            cout << s[i];
        else {
            if (s[i] == ')') {
                while (stk.top() != '(') {
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else {
                if (s[i] != '(' && !stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                    cout << stk.top();
                    stk.pop();
                }
                if ((s[i] == '+' || s[i] == '-')) {
                    while (!stk.empty() && (stk.top() == '+' || stk.top() == '-')) {
                        cout << stk.top();
                        stk.pop();
                    }
                }
                stk.push(s[i]);
            }
        }
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}