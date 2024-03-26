#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fastio;

    int d;
    cin >> d;
    string s;
    while (d--) {
        cin >> s;
        cout << s[0] + s[2] + 2 * (-'1' + 1) << '\n';
    }

    return 0;
}