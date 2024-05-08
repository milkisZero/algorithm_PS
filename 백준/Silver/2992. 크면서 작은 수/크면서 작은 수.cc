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

    string s;
    cin >> s;

    ll n = stoll(s), res = LLINF;
    sort(s.begin(), s.end());
    do {
        ll k = stoll(s);
        if (n < k) res = min(res, k);
    } while (next_permutation(s.begin(), s.end()));

    if (res == LLINF) cout << 0;
    else cout << res;

    return 0;
}