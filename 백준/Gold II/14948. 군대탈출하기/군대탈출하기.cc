#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int arr[101][101];
int visited[101][101][2];
int n, m, res = INF;

typedef struct info {
    int val, cnt;
    int x, y;
    bool operator<(const info &o) const {
        return val > o.val;
    }
} INFO;

priority_queue<INFO> q;

void move(int a, int b, int cnt, int val) {
    if (a == n - 1 && b == m - 1) {
        res = min(res, max(arr[n - 1][m - 1], val));
        return;
    }

    if (a >= 0 && a < n && b >= 0 && b < m) {
        if (visited[a][b][cnt] == -1) {
            visited[a][b][cnt] = max(val, arr[a][b]);
            q.push({visited[a][b][cnt], cnt, a, b});
        }
    }
}

void bfs() {
    fill(&visited[0][0][0], &visited[n][m][2], -1);
    visited[0][0][0] = arr[0][0];
    q.push({arr[0][0], 0, 0, 0});

    while (!q.empty()) {
        pi cur = {q.top().x, q.top().y};
        int cnt = q.top().cnt;
        int val = q.top().val;
        q.pop();

        for (int i = -1; i <= 1; i += 2) {
            move(cur.first + i, cur.second, cnt, val);
            move(cur.first, cur.second + i, cnt, val);
            if (cnt == 0) {
                move(cur.first, cur.second + i + i, 1, val);
                move(cur.first + i + i, cur.second, 1, val);
            }

            if (res != INF)
                return;
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    if (n == 1 && m == 1) {
        cout << arr[0][0];
        return 0;
    }

    bfs();

    cout << res;

    return 0;
}