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

    ll L;
    cin >> L;

    vector<ll> v(L);
    for (auto &e : v) {
        cin >> e;
    }

    ll n;
    cin >> n;

    sort(v.begin(), v.end());

    ll mini = 0, maxi = v[L - 1];
    for (auto e : v) {
        if (e <= n) mini = max(mini, e);
        else maxi = min(maxi, e);
    }

    if (mini == n) {
        cout << 0;
        return 0;
    }

    maxi--, mini++;

    cout << (maxi - n) + (n - mini) + (maxi - n) * (n - mini);

    return 0;
}