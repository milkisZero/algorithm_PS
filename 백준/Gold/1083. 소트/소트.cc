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

    ll n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        ll num = i;

        ll idx = -1, maxi = -1;
        for (int i = num + 1; i < n; i++) {
            if (v[num] < v[i] && i - num <= s) {
                if (maxi < v[i]) {
                    idx = i;
                    maxi = v[i];
                }
            }
        }
        if (idx == -1) continue;

        for (int i = idx; i > num; i--) swap(v[i], v[i - 1]);
        s -= idx - num;

        if (s == 0) break;
    }

    for (auto e : v) cout << e << sp;

    return 0;
}