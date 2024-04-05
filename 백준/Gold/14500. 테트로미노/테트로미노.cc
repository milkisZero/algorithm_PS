#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
int n, m;
int arr[505][505], visi[505][505];
vector<pll> add = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool inmap(int a, int b) {
    return (a < n && b < m && a >= 0 && b >= 0);
}

ll res;
void recur(int a, int b, int cnt, ll sum) {
    visi[a][b] = 1;
    sum += arr[a][b];
    if (cnt == 4) {
        res = max(res, sum);
        return;
    }
    for (auto [x, y] : add) {
        if (inmap(a + x, b + y) && !visi[a + x][b + y]) {
            recur(a + x, b + y, cnt + 1, sum);
            visi[a + x][b + y] = 0;
        }
    }
}

void recur2(int a, int b) {
    priority_queue<ll> pq;
    for (auto [x, y] : add) {
        if (inmap(a + x, b + y))
            pq.push(arr[a + x][b + y]);
    }
    if (pq.size() < 3) return;
    ll sum = arr[a][b];
    int n = 3;
    while (!pq.empty() && n--) {
        sum += pq.top();
        pq.pop();
    }
    res = max(res, sum);
}

int main() {
    fastio;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            recur(i, j, 1, 0);
            visi[i][j] = 0;
            recur2(i, j);
        }
    }
    cout << res;

    return 0;
}