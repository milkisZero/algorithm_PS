// #유파
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int x1[1003], x2[1003], y1[1003], y2[1003];
int par[1003];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int find(int a) {
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b) {
    if (a > b)
        swap(a, b);

    if (find(a) != find(b))
        par[find(a)] = find(b);
}

int overlap(int a, int b) {
    if (x2[b] < x1[a] || x2[a] < x1[b])
        return 0;
    if (y2[b] < y1[a] || y2[a] < y1[b])
        return 0;

    if (x1[b] < x1[a] && x2[a] < x2[b] && y1[b] < y1[a] && y2[a] < y2[b])
        return 0;
    if (x1[a] < x1[b] && x2[b] < x2[a] && y1[a] < y1[b] && y2[b] < y2[a])
        return 0;
    return 1;
}

int main() {
    fastio();

    int n;
    cin >> n;
    init(n);

    int cnt = 0, check = 1;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        x1[i] = a, y1[i] = b, x2[i] = c, y2[i] = d;
        if (check && ((!a && (b <= 0 && d >= 0)) || (!c && (b <= 0 && d >= 0)))) {
            cnt--;
            check = 0;
        }
        else if (check && ((!b && (a <= 0 && c >= 0)) || (!d && (a <= 0 && c >= 0)))) {
            cnt--;
            check = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (overlap(i, j))
                uni(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == par[i]) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}