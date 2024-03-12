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

    ull a;
    cin >> a;

    ull b = 64, res = 1;
    for (int i = 1; i <= b; i++) {
        res *= 2;
        ull tmp = res - 1;
        for (int j = i + 1; j <= b; j++) {
            tmp *= 2;
        }
        if (tmp == a) {
            cout << i;
            break;
        }
    }
    return 0;
}