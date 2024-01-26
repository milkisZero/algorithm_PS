#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> f[1003], e[1003];
int par[1003];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int find(int a) {
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b) {
    if (a > b)
        swap(a, b);

    if (find(a) != find(b))
        par[find(a)] = find(b);
}

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if (s == "E") {
            e[a].push_back(b);
            e[b].push_back(a);
        }
        else {
            f[a].push_back(b);
            f[b].push_back(a);
        }
    }

    init(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            int p = e[i][j];
            for (int k = 0; k < e[p].size(); k++) {
                if (i != e[p][k])
                    uni(i, e[p][k]);
            }
        }

        for (int j = 0; j < f[i].size(); j++) {
            int p = f[i][j];
            uni(i, f[i][j]);
            for (int k = 0; k < f[p].size(); k++) {
                if (i != f[p][k])
                    uni(i, f[p][k]);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == par[i]) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}