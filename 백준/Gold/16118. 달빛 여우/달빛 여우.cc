#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<pi> v[4004];
ll d[4004];
ll d2[4004][2];
priority_queue<pi> pq;
priority_queue<pair<pll, int>> pq2;

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    fill(d + 1, d + n + 1, LLINF);
    d[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll x = -pq.top().first;
        pq.pop();

        if (x == d[u]) {
            for (auto &p : v[u]) {
                ll q = p.first;
                if (p.second * 2 + x < d[q]) {
                    d[q] = p.second * 2 + x;
                    pq.push({-d[q], q});
                }
            }
        }
    }

    fill(&d2[0][0], &d2[4003][2], LLINF);
    d2[1][1] = 0;
    pq2.push({{0, 1}, 1});

    while (!pq2.empty()) {
        ll u = pq2.top().first.second;
        ll x = -pq2.top().first.first;
        ll s = pq2.top().second;
        pq2.pop();

        if (x == d2[u][s]) {
            for (auto &p : v[u]) {
                ll q = p.first;
                if (s == 1 && p.second + x < d2[q][0]) {
                    d2[q][0] = p.second + x;
                    pq2.push({{-d2[q][0], q}, !s});
                }
                else if (s == 0 && p.second * 4 + x < d2[q][1]) {
                    d2[q][1] = p.second * 4 + x;
                    pq2.push({{-d2[q][1], q}, !s});
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (d[i] < min(d2[i][0], d2[i][1]))
            cnt++;
    }

    cout << cnt;

    return 0;
}