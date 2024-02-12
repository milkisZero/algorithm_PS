#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    ll pref = 0;
    map<ll, ll> m;
    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        pref += tmp;
        m[pref - k * i]++;
    }

    ll cnt = m[0];
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        ll q = iter->second;
        cnt += (q - 1) * q / 2;
    }

    cout << cnt;

    return 0;
}