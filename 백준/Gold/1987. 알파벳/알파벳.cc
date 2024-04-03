#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

string s[25];
ll r, c, res;
ll visited[25][25];
vector<pll> add = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
map<char, ll> mp;

bool inmap(ll a, ll b) {
    return (a < r && b < c && a >= 0 && b >= 0);
}

void dfs(ll a, ll b, ll cnt) {
    res = max(res, cnt);
    visited[a][b] = 1;
    char cur = s[a][b];
    mp[cur] = 1;
    for (auto [x1, x2] : add) {
        if (inmap(a + x1, b + x2) && mp[s[a + x1][b + x2]] == 0 && visited[a + x1][b + x2] == 0) {
            dfs(a + x1, b + x2, cnt + 1);
            mp[s[a + x1][b + x2]] = 0;
            visited[a + x1][b + x2] = 0;
        }
    }
}

int main() {
    fastio;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }

    dfs(0, 0, 1);
    cout << res;

    return 0;
}