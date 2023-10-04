#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int d[100005];                    // 시작부터 정점까지 최단거리 배열, 결과배열
vector<pair<int, int>> e[100005]; // 간선정보
priority_queue<pair<int, int>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int k, m, n, x, y, z;
    // 정점개수, 간선개수, 시작노드
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        // e[y].push_back({x, z}); // 무향일 경우 양쪽 다 저장
    }

    fill(d + 1, d + n + 1, 1 << 30);
    d[k] = 0;

    for (Q.push({0, k}); Q.size();) { // {거리, 번호}
        int u = Q.top().second;
        x = -Q.top().first;
        Q.pop();
        if (x == d[u]) {
            for (auto &p : e[u]) {
                int v = p.first;
                if (x + p.second < d[v]) {
                    d[v] = x + p.second;
                    Q.push({-d[v], v}); // priority 때문에 음수로
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] == 1 << 30)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }

    return 0;
}