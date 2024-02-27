#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <set>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<pll> e[10004];
vector<pll> e2[10004];
ll d[10004];
ll visited[10004];
ll ind[10004];

int main() {
    fastio;

    ll n, m, start, end;
    cin >> n >> m;

    ll x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e2[y].push_back({x, z});
        ind[y]++;
    }
    cin >> start >> end;

    priority_queue<pll> Q;
    for (Q.push({0, start}); Q.size();) {
        ll u = Q.top().second;
        x = -Q.top().first;
        Q.pop();

        if (x == d[u]) {
            for (auto p : e[u]) {
                ll v = p.first;
                if (p.second + x > d[v]) {
                    d[v] = p.second + x;
                }
                ind[v]--;
                if (ind[v] == 0)
                    Q.push({-d[v], v});
            }
        }
    }
    cout << d[end] << '\n';
    
    set<pll> road;
    for (Q.push({d[end], end}); Q.size();) {
        ll u = Q.top().second;
        x = Q.top().first;
        Q.pop();

        if (x == d[u]) {
            for (auto p : e2[u]) {
                ll v = p.first;
                if (x - p.second == d[v]) {
                    if (road.find({u, v}) == road.end()) {
                        Q.push({d[v], v});
                        road.insert({u, v});
                    }
                }
            }
        }
    }
    cout << road.size();

    return 0;
}