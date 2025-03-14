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

map<ll, vector<ll>> mp;
ll scnt[100005];
ll kcnt[100005];

int main() {
    fastio;

    string s;
    cin >> s;
    s = ' ' + s;

    ll sum = 0;
    mp[0].push_back(0);
    for (int i = 1; i <= s.length() - 1; i++) {
        scnt[i] = scnt[i - 1];
        kcnt[i] = kcnt[i - 1];
        if (s[i] == 'S') {
            sum += 2;
            scnt[i]++;
        }
        else if (s[i] == 'K') {
            sum -= 1;
            kcnt[i]++;
        }

        mp[sum].push_back(i);
    }

    ll res = -1;
    for (auto [k, v] : mp) {
        if (scnt[v.back()] - scnt[v[0]] == 0 || kcnt[v.back()] - kcnt[v[0]] == 0) continue;
        res = max(res, v.back() - v[0]);
    }

    cout << res;

    return 0;
}