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

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> v(k);
    for (int i = 0; i < k; i++) cin >> v[i];

    ll l = 1, r = n, mid;
    string res;
    while (l <= r) {
        mid = (l + r) / 2;
        ll cnt = 1, prev = 0;
        string s = "1";
        for (int i = 1; i < k; i++) {
            if (v[i] - v[prev] >= mid && cnt < m) {
                prev = i;
                cnt++;
                s = s + '1';
            }
            else s = s + '0';
        }

        if (cnt == m) {
            res = s;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res;

    return 0;
}