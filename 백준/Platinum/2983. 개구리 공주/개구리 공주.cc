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

    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    set<tuple<ll, ll, ll>> AD, BC;
    ll x, y;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        AD.insert({a - b, a, b});
        BC.insert({a + b, a, b});
        if (!i) x = a, y = b;
    }

    for (int i = 0; i < k; i++) {
        if (s[i] == 'A') {
            auto iter = AD.find({x - y, x, y});
            auto [a, b, c] = *(++iter);
            if (iter != AD.end() && a == x - y) {
                AD.erase({x - y, x, y});
                BC.erase({x + y, x, y});
                x = b, y = c;
            }
        }
        else if (s[i] == 'B') {
            auto iter = BC.find({x + y, x, y});
            auto [a, b, c] = *(++iter);
            if (iter != BC.end() && a == x + y) {
                AD.erase({x - y, x, y});
                BC.erase({x + y, x, y});
                x = b, y = c;
            }
        }
        else if (s[i] == 'C') {
            auto iter = BC.find({x + y, x, y});
            if (iter == BC.begin()) continue;
            auto [a, b, c] = *(--iter);
            if (a == x + y) {
                AD.erase({x - y, x, y});
                BC.erase({x + y, x, y});
                x = b, y = c;
            }
        }
        else if (s[i] == 'D') {
            auto iter = AD.find({x - y, x, y});
            if (iter == AD.begin()) continue;
            auto [a, b, c] = *(--iter);
            if (a == x - y) {
                AD.erase({x - y, x, y});
                BC.erase({x + y, x, y});
                x = b, y = c;
            }
        }
    }

    cout << x << ' ' << y;

    return 0;
}