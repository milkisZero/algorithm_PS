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

int par[100005];
int n, m;

struct edge {
    int a, b, cost;
    bool operator<(const edge &o) const {
        return cost < o.cost;
    }
};
vector<edge> _edges;

void init() {
    for (int i = 0; i <= n; i++)
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
        par[find(b)] = find(a);
}

int kruskal() {
    int ret = 0;
    init();
    sort(_edges.begin(), _edges.end());
    for (int i = 0; i < _edges.size(); i++) {
        edge e = _edges[i];
        if (find(e.a) != find(e.b)) {
            uni(e.a, e.b);
            if (ret == e.cost || ret + 1 == e.cost)
                ret = e.cost;
            else
                break;
        }
    }
    return ret + 1;
}

int main() {
    fastio();

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        _edges.push_back({a, b, c});
    }

    cout << kruskal();

    return 0;
}