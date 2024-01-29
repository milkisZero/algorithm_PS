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

string s[505];
int d[505][505];
priority_queue<pair<int, pi>> pq;

int wall(int a, int b) {
    if (s[a + 1][b] == '#' || s[a - 1][b] == '#' || s[a][b + 1] == '#' || s[a][b - 1] == '#')
        return 1;
    return 0;
}

int main() {
    fastio();

    int h, w;
    cin >> h >> w;

    int x, y, ex, ey;
    for (int i = 1; i <= h; i++) {
        cin >> s[i];
        for (int j = 1; j <= w; j++) {
            if (s[i][j] == 'S')
                x = i, y = j;
            else {
                if (s[i][j] == 'E')
                    ex = i, ey = j;
                d[i][j] = INF;
            }
        }
    }

    pq.push({0, {x, y}});
    while (!pq.empty()) {

        pi u = pq.top().second;
        int x = -pq.top().first;
        pq.pop();

        if (x == d[u.first][u.second]) {
            for (int i = -1; i <= 1; i += 2) {
                int ux = u.first + i, uy = u.second + i;

                int v = 1;
                if (wall(u.first, u.second) && wall(ux, u.second))
                    v = 0;

                if (s[ux][u.second] != '#' && x + v < d[ux][u.second]) {
                    d[ux][u.second] = x + v;
                    pq.push({-d[ux][u.second], {ux, u.second}});
                }

                v = 1;
                if (wall(u.first, u.second) && wall(u.first, uy))
                    v = 0;

                if (s[u.first][uy] != '#' && x + v < d[u.first][uy]) {
                    d[u.first][uy] = x + v;
                    pq.push({-d[u.first][uy], {u.first, uy}});
                }
            }
        }
    }

    cout << d[ex][ey];

    return 0;
}