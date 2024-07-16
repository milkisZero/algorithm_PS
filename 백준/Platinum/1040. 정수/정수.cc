#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 19

ll n, k;
string s;
ll dp[20][1 << 10][2][2];

ll solve(ll pos, ll used, bool bigger, bool leading0) {
    ll &val = dp[pos][used][bigger][leading0];
    if (val != -1) return val;

    if (pos == MAX) {
        if (!bigger) return val = -2;

        ll cnt = __builtin_popcount(used);
        if (cnt != k) return val = -2;

        return val = 0;
    }

    val = 0;
    ll posN = s[pos] - '0';
    if (leading0 && posN == 0) {
        ll next = solve(pos + 1, used, bigger, leading0);
        if (next >= 0) return val = next;
    }

    for (int i = (bigger ? 0 : posN); i < 10; i++) {
        if (leading0 && i == 0) continue;

        ll next = solve(pos + 1, used | (1 << i), bigger || (i > posN), 0);
        if (next >= 0) return val = next + (ll)pow(10ll, MAX - pos - 1) * i;
    }
    return val = -2;
}

int main() {
    fastio;

    cin >> n >> k;
    s = to_string(n - 1);

    while (s.length() < MAX) s = "0" + s;

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0, 1);

    return 0;
}