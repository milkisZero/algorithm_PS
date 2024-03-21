#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    int n;
    cin >> n;

    if (n == 1) {
        cout << "YES\n1";
        return 0;
    }
    else if (n == 2) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n1 3 2 ";
    for (int i = 4; i <= n; i++) {
        cout << i << ' ';
    }

    return 0;
}