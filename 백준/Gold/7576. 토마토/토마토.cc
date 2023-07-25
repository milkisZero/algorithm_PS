#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int x, y, cnt;
} info;
int box[2003][2003];
int visited[2003][2003];
queue<info> q;
int res;

void bfs() {
    while (!q.empty()) {
        info tmp = q.front();
        visited[tmp.x][tmp.y] = 1;

        q.pop();

        pair<int, int> arr[4] =
            {make_pair(tmp.x + 1, tmp.y),
             make_pair(tmp.x - 1, tmp.y),
             make_pair(tmp.x, tmp.y - 1),
             make_pair(tmp.x, tmp.y + 1)};

        for (int i = 0; i < 4; i++) {
            if (visited[arr[i].first][arr[i].second] == 0 && box[arr[i].first][arr[i].second] == 0) {
                info tmp2;
                tmp2.x = arr[i].first, tmp2.y = arr[i].second, tmp2.cnt = tmp.cnt + 1;
                q.push(tmp2);

                box[arr[i].first][arr[i].second] = 1;

                res = max(res, tmp2.cnt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(box, -1, sizeof(box));

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                info tmp;
                tmp.x = i, tmp.y = j, tmp.cnt = 0;
                q.push(tmp);
            }
        }
    }

    bfs();

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << res;

    return 0;
}