#include <bits/stdc++.h>
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
    fastio;

    ll n, p, q;
    cin >> n >> p >> q;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> res;
    for (int i = 0; i < n; i++) {
        ll cnt = 0;
        while (a[i] != b[i]) {
            a[i] += p;
            b[i] += q;
            cnt++;

            if (cnt > 10000) {
                cout << "NO";
                return 0;
            }
        }

        res.push_back(cnt);
    }

    cout << "YES\n";
    for (auto e : res) cout << e << ' ';

    return 0;
}