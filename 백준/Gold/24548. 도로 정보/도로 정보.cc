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

ll cnt[100005][4];
map<vector<ll>, ll> mp;

int main() {
    fastio;

    ll n;
    cin >> n;

    string s;
    cin >> s;
    s = ' ' + s;

    mp[{0, 0, 0, 0}] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) cnt[i][j] = cnt[i - 1][j];
        if (s[i] == 'T') cnt[i][0] = (cnt[i - 1][0] + 1) % 3;
        else if (s[i] == 'G') cnt[i][1] = (cnt[i - 1][1] + 1) % 3;
        else if (s[i] == 'F') cnt[i][2] = (cnt[i - 1][2] + 1) % 3;
        else if (s[i] == 'P') cnt[i][3] = (cnt[i - 1][3] + 1) % 3;

        mp[{cnt[i][0], cnt[i][1], cnt[i][2], cnt[i][3]}]++;
    }

    ll res = 0;
    for (auto [a, b] : mp) {
        res += (b * (b - 1)) / 2;
    }
    cout << res;

    return 0;
}