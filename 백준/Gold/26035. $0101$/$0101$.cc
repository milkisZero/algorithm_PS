#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MOD ((ll)1e9 + 7)

ull powN(ull a, ll b) {
    ull res = 1;
    while (b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    fastio;

    ull n, m;
    cin >> n >> m;

    cout << (powN(2, n) + powN(2, m) - 2) % MOD;

    return 0;
}