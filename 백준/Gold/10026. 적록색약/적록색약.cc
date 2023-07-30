#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int visited[100][100];
string color[100];
int n;

void bfs(int x, int y) {
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    char tmp = color[x][y];

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = -1; i <= 1; i++) {
            if ((curX + i >= 0 && curX + i < n) && tmp == color[curX + i][curY] && !visited[curX + i][curY]) {
                q.push({curX + i, curY});
                visited[curX + i][curY] = 1;
            }
            if ((curY + i >= 0 && curY + i < n) && tmp == color[curX][curY + i] && !visited[curX][curY + i]) {
                q.push({curX, curY + i});
                visited[curX][curY + i] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    int cnt[2] = {0};
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bfs(i, j);
                    cnt[k]++;
                }

                if (color[i][j] == 'G')
                    color[i][j] = 'R';
            }
        }
        memset(visited, 0, sizeof(visited));
    }

    cout << cnt[0] << ' ' << cnt[1];

    return 0;
}