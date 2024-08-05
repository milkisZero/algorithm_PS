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

    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    unordered_map<ll, bool> mp;
    for (ll i = 2; i <= sqrt(b); i++) {
        for (ll j = a / (i * i); j * i * i <= b; j++) {
            mp[j * i * i] = 1;
        }
    }

    ll cnt = 0;
    for (ll i = a; i <= b; i++) {
        if (mp.find(i) == mp.end()) cnt++;
    }

    cout << cnt;

    return 0;
}