#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    fastio;
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
    return 0;
}