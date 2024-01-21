#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int pointX[100006], pointY[100006];
string command;

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    ll prev = 0;
    for (int i = 0; i < n; i++) {
        cin >> pointX[i] >> pointY[i];
        prev += abs(pointX[i]) + abs(pointY[i]);
    }

    sort(pointX, pointX + n);
    sort(pointY, pointY + n);

    cin >> command;

    int x = 0, y = 0, u, l;
    for (int i = 0; i < m; i++) {
        int k = 0;
        if (command[i] == 'S' || command[i] == 'J') {
            if (command[i] == 'S') {
                y++;
                k = 1;
            }
            else
                y--;
            u = upper_bound(pointY, pointY + n, y) - pointY;
            l = lower_bound(pointY, pointY + n, y) - pointY;
        }
        else {
            if (command[i] == 'I') {
                x++;
                k = 1;
            }
            else
                x--;
            u = upper_bound(pointX, pointX + n, x) - pointX;
            l = lower_bound(pointX, pointX + n, x) - pointX;
        }

        if (k)
            prev += -n + u + l;
        else
            prev += n - u - l;

        prev -= u - l;

        cout << prev << '\n';
    }

    return 0;
}