#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll d[1003][1003];
ll visited[1003][1003];
vector<pll> e[10005];
priority_queue<tuple<ll, ll, ll>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll n, p, k;
    cin >> n >> p >> k;

    ll x, y, z;
    for (int i = 1; i <= p; i++) {
        cin >> x >> y >> z;
        e[y].push_back({x, z});
        e[x].push_back({y, z});
    }

    fill(&d[0][0], &d[n + 1][k + 1], LLINF);

    d[1][0] = 0;
    // max, k 카운트, 노드번호,
    Q.push(make_tuple(0, 0, 1));

    for (; Q.size();) {
        ll u, x, cnt;
        tie(x, cnt, u) = Q.top();
        x = -x;
        Q.pop();
        if (visited[u][cnt] == 0) {
            for (auto &p : e[u]) {
                ll v = p.first;

                if (p.second < x && visited[v][cnt] == 0 && d[v][cnt] > x) {
                    d[v][cnt] = x;
                    Q.push(make_tuple(-d[v][cnt], cnt, v));
                }
                else {
                    if (k >= cnt + 1 && visited[v][cnt + 1] == 0 && d[v][cnt + 1] > x) {
                        d[v][cnt + 1] = x;
                        Q.push(make_tuple(-d[v][cnt + 1], cnt + 1, v));
                    }
                    if (visited[v][cnt] == 0 && d[v][cnt] > p.second) {
                        d[v][cnt] = p.second;
                        Q.push(make_tuple(-d[v][cnt], cnt, v));
                    }
                }
            }
            visited[u][cnt] = 1;
        }
    }

    if (d[n][k] == LLINF)
        cout << -1;
    else
        cout << d[n][k];

    return 0;
}