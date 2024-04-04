// #dfs
// 탐색 전 상태를 분할 저장해야 속도를 빠르게 할 수 있다
#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<pi> add = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
vector<string> bog(5);
map<string, bool> mp;
ll score;
string ls = "", k;

bool inmap(int a, int b) {
    return (a >= 0 && b >= 0 && a < 4 && b < 4);
}

bool dfs(int a, int b, int idx, int visi) {
    visi |= 1 << a * 4 + b;
    int klen = k.length();
    if (klen - 1 == idx) {
        if (ls.length() < klen) ls = k;
        else if (ls.length() == klen && ls > k) ls = k;

        if (klen == 4 || klen == 3) score++;
        else if (klen == 5) score += 2;
        else if (klen == 6) score += 3;
        else if (klen == 7) score += 5;
        else if (klen == 8) score += 11;
        mp[k] = 1;
        return 1;
    }

    for (auto [x, y] : add) {
        if (inmap(a + x, b + y) && !(visi & 1 << 4 * (a + x) + b + y) && k[idx + 1] == bog[a + x][b + y]) {
            if (dfs(a + x, b + y, idx + 1, (visi | 1 << 4 * (a + x) + b + y))) return 1;
        }
    }
    return 0;
}

int main() {
    fastio;

    ll n, m;
    cin >> n;
    vector<string> sv(n);
    for (int i = 0; i < n; i++) cin >> sv[i];
    cin >> m;

    while (m--) {
        map<char, vector<pll>> tile;
        for (int i = 0; i < 4; i++) {
            cin >> bog[i];
            for (int j = 0; j < 4; j++) {
                tile[bog[i][j]].push_back({i, j});
            }
        }

        int check;
        for (auto e : sv) {
            check = 0;
            for (auto [x, y] : tile[e[0]]) {
                k = e;
                if (dfs(x, y, 0, 0)) check = 1;
                if (check) break;
            }
        }

        cout << score << ' ' << ls << ' ' << mp.size() << '\n';
        mp.clear();
        bog.clear();
        ls = "";
        score = 0;
    }
    return 0;
}