#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

vector<ll> e[10005], e2[10005];
int visited[10005];
ll point[10005];
ll n;

ll find(int r) {
    if (e2[r].empty())
        return point[r] = 1;

    for (auto k : e2[r]) {
        point[r] += find(k);
    }
    return point[r] += 1;
}

void bfs(int r) {
    memset(visited, 0, sizeof(visited));
    visited[r] = 1;

    queue<ll> q;
    q.push(r);

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        for (auto k : e[cur]) {
            if (!visited[k]) {
                visited[k] = 1;
                e2[cur].push_back(k);
                q.push(k);
            }
        }
    }
}

int main() {
    fastio;

    ll k, p;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> k;
        while (k--) {
            cin >> p;
            e[p].push_back(i);
        }
    }

    ll res = LLINF;
    for (int i = 1; i <= n; i++) {
        bfs(i);
        find(i);

        ll sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += point[j];
        }

        ll check = 0;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == 0)
                check = 1;
        }
        if (!check)
            res = min(res, sum);

        for (int j = 1; j <= n; j++) {
            e2[j].clear();
        }
        memset(point, 0, sizeof(point));
    }

    cout << res;

    return 0;
}