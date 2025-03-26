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

int main() {
    fastio;

    ll n, M, L;
    cin >> n >> M >> L;
    L--;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll res = LLINF;
    ll l = 1, r = L - 1, m;
    while (l <= r) {
        m = (l + r) / 2;

        ll prev = 0;
        ll cnt = 0, leng = 0;
        ll idx = 0, maxi = 0;
        while (leng <= L) {
            prev = leng;

            if (idx < n && leng + m >= v[idx]) {
                leng = v[idx];
                idx++;
            }
            else {
                leng += m;
                cnt++;
            }

            if (leng > L) {
                cnt--;
                break;
            }

            maxi = max(maxi, leng - prev);
        }
        maxi = max(maxi, L - prev);

        if (cnt <= M) res = min(res, maxi);

        if (cnt > M) l = m + 1;
        else r = m - 1;
    }

    cout << res;

    return 0;
}