#include <iostream>
#include <string>
using namespace std;

string stack;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    char a;
    cin >> a;
    stack.push_back(a);

    for (int i = 1; i < n; i++) {
        char a;
        cin >> a;

        if (m != 0) {
            while (a > stack.back() && !stack.empty() && m > 0) {
                stack.pop_back();
                m--;
            }
            stack.push_back(a);
        }
        else
            stack.push_back(a);
    }

    while (!stack.empty() && m > 0) {
        stack.pop_back();
        m--;
    }

    cout << stack;

    return 0;
}