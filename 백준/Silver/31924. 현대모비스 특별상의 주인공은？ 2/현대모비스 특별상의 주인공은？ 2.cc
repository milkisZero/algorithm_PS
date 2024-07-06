#include <bits/stdc++.h>
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

string s[103];
int visited[103][103];
pll mov[8] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
map<char, char> mp;
ll n;
ll cnt;

bool outmap(ll x, ll y) {
    return (x < 0 || x >= n || y < 0 || y >= n);
}

void dfs(ll x, ll y, ll dir) {
    visited[x][y] = 1;

    char next = mp[s[x][y]];

    if (next == 'K') {
        cnt++;
        return;
    }

    auto [a, b] = mov[dir];

    if (!outmap(x + a, y + b) && visited[x + a][y + b] == 0 && next == s[x + a][y + b]) {
        dfs(x + a, y + b, dir);
    }
}

int main() {
    fastio;

    mp['M'] = 'O';
    mp['O'] = 'B';
    mp['B'] = 'I';
    mp['I'] = 'S';
    mp['S'] = 'K';

    cin >> n;

    vector<pll> v;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'M') v.push_back({i, j});
        }
    }

    for (auto [x, y] : v) {
        for (int i = 0; i < 8; i++) {
            dfs(x, y, i);
            memset(visited, 0, sizeof(visited));
        }
    }

    cout << cnt;

    return 0;
}