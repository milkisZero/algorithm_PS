#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

vector<pair<int, int>> node[100006];
int visited[100006];
ll res;

ll dfs(int cur) {
    visited[cur] = 1;

    priority_queue<ll> pq;
    for (int i = 0; i < node[cur].size(); i++) {
        ll tmp = 0;
        if (!visited[node[cur][i].first]) {
            tmp = dfs(node[cur][i].first);
            pq.push(tmp + node[cur][i].second);
        }
    }

    if (pq.size() == 1)
        return pq.top();
    else if (!pq.size())
        return 0;
    else {
        ll tmp1 = pq.top();
        pq.pop();
        res = max(res, tmp1 + pq.top());
        return tmp1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int v;
    cin >> v;

    while (v--) {
        int s, e, dist;
        cin >> s;

        while (1) {
            cin >> e;
            if (e == -1)
                break;
            cin >> dist;
            node[s].push_back({e, dist});
        }
    }

    cout << max(res, dfs(1));

    return 0;
}