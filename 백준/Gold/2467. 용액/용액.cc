#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll n, k;
ll val = LLINF;
vector<ll> v;
pi res;

void bs(int k) {
    ll l = 0, r = n - 1, m;
    while (l <= r) {
        m = (r + l) / 2;

        if (m != k && abs(v[m] + v[k]) < val) {
            val = abs(v[m] + v[k]);
            res = {v[m], v[k]};
        }

        if (val == 0 && m != k)
            return;

        if (v[m] + v[k] < 0)
            l = m + 1;
        else
            r = m - 1;
    }
}

int main() {
    fastio;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        bs(i);
        if (val == 0)
            break;
    }

    auto [a, b] = res;
    if (a > b)
        swap(a, b);
    cout << a << ' ' << b;

    return 0;
}