#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll res = 0;

    for (int i = 1; i <= n; i++) {
        ll k = 0, cnt = 0;
        for (int j = 1; j <= i - 1; j++) {
            if (k + a <= v[j]) {
                k += a;
                cnt++;
            }
        }

        for (int p = 0; p < a; p++) {
            ll ttt = b * p;

            ll sk = k + ttt, scnt = cnt;
            for (int j = i; j <= n; j++) {
                if (sk + a - p <= v[j]) {
                    sk += a - p;
                    scnt++;
                }
            }
            res = max(res, scnt);
        }

        res = max(res, cnt);
    }

    ll k = 0, cnt = 0;
    for (int j = 1; j <= n; j++) {
        if (k + a <= v[j]) {
            k += a;
            cnt++;
        }
    }

    cout << max(cnt, res);

    return 0;
}