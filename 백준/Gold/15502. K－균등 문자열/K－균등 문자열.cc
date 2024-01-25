#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007

int par[100005];

void init(int n) {
    for (int i = 1; i <= n; i++)
        par[i] = i;
}

int find(int a) {
    if (par[a] == a)
        return a;
    else
        return par[a] = find(par[a]);
}

void uni(int a, int b) {
    if (find(a) != find(b))
        par[find(a)] = find(b);
}

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    init(n);

    for (int i = 0; i < m; i++) {
        int s, e, k;
        cin >> s >> e >> k;
        for (int j = s; j + k <= e; j++) {
            uni(j, j + k);
        }
    }

    int res = 1;
    for (int i = 1; i <= n; i++) {
        if (i == find(i))
            res *= 2;
        res %= MOD;
    }

    cout << res;

    return 0;
}