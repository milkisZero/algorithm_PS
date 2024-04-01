#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    fastio;
    int e, s, m, x = 0, y = 0, z = 0, i = 0;
    cin >> e >> s >> m;

    while (1) {
        i++;
        x++;
        y++;
        z++;
        if (x == 16)
            x = 1;
        if (y == 29)
            y = 1;
        if (z == 20)
            z = 1;
        if (x == e && y == s && z == m) {
            cout << i;
            return 0;
        }
    }

    return 0;
}