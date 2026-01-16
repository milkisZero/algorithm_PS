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

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<pll> v(n);
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            v[i] = {a, b};
        }

        sort(v.begin(), v.end());

        ll head = v[0].second;
        ll res = 1;
        for (int i = 1; i < n; i++) {
            if (head < v[i].second) continue;
            head = v[i].second;
            res++;

            if (head == 1) break;
        }

        cout << res << endl;
    }

    return 0;
}