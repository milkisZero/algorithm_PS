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
#define MOD 1000000007

ll cnt[4];

ll powN(ll a, ll b) {
    ll k = 1;
    while (b) {
        if (b % 2) k = (k * a) % MOD;
        b /= 2;
        a = (a * a) % MOD;
    }
    return k;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') cnt[0] = (cnt[0] + powN(2, i)) % MOD;
        else if (s[i] == 'O') cnt[1] = (cnt[1] + cnt[0]) % MOD;
        else if (s[i] == 'C') cnt[2] = (cnt[2] + cnt[1]) % MOD;
        else if (s[i] == 'K') res = (res + cnt[2]) % MOD;
    }

    cout << res;

    return 0;
}