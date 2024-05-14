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

    unordered_map<string, string> mp;
    string a, b;
    while (n--) {
        cin >> a >> b;
        mp[a] = b;
    }
    while (k--) {
        cin >> a;
        cout << mp[a] << '\n';
    }

    return 0;
}