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

    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &e : v) cin >> e;

    ll cnt = 0;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {

            ll a = 0;
            while (v[i - 1] > v[i] * pow(2, a)) {
                a++;
            }

            v[i] *= pow(2, a);
            cnt += a;
        }
    }

    cout << cnt;

    return 0;
}