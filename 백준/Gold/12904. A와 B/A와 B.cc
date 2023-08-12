#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    while (a.length() <= b.length()) {
        if (a == b) {
            cout << 1;
            return 0;
        }

        if (b[b.length() - 1] == 'A') {
            b.erase(b.begin() + b.length() - 1);
        }
        else if (b[b.length() - 1] == 'B') {
            b.erase(b.begin() + b.length() - 1);
            reverse(b.begin(), b.end());
        }
        else {
            cout << 0;
            return 0;
        }
    }

    cout << 0;

    return 0;
}