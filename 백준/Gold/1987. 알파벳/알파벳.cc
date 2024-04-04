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

bool inmap(ll a, ll b) {
    return (a < r && b < c && a >= 0 && b >= 0);
}

void dfs(ll a, ll b, ll cnt, int bit) {
    res = max(res, cnt);
    visited[a][b] = 1;
    bit |= 1 << s[a][b] - 'A';
    for (auto [x1, x2] : add) {
        if (inmap(a + x1, b + x2) && !(bit & (1 << s[a + x1][b + x2] - 'A')) && !visited[a + x1][b + x2]) {
            dfs(a + x1, b + x2, cnt + 1, bit);
            visited[a + x1][b + x2] = 0;
        }
    }
}

int main() {
    fastio;
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> s[i];
    dfs(0, 0, 1, 0);
    cout << res;
    return 0;
}