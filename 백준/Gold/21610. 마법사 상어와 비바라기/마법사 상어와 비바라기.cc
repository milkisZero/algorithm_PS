#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll arr[55][55];
ll cloud[55][55];
ll cloud2[55][55];
ll n, m;

void mov(ll d, ll s, ll r, ll c) {
    s = s % n;

    if (d == 1) {
        c -= s;
        if (c < 1) c = n + c;
    }
    if (d == 2) {
        c -= s;
        if (c < 1) c = n + c;
        r -= s;
        if (r < 1) r = n + r;
    }
    if (d == 3) {
        r -= s;
        if (r < 1) r = n + r;
    }
    if (d == 4) {
        c += s;
        if (c > n) c = c - n;
        r -= s;
        if (r < 1) r = n + r;
    }
    if (d == 5) {
        c += s;
        if (c > n) c = c - n;
    }
    if (d == 6) {
        c += s;
        if (c > n) c = c - n;
        r += s;
        if (r > n) r = r - n;
    }
    if (d == 7) {
        r += s;
        if (r > n) r = r - n;
    }
    if (d == 8) {
        c -= s;
        if (c < 1) c = n + c;
        r += s;
        if (r > n) r = r - n;
    }

    cloud2[r][c] = 1;
}

int main() {
    fastio;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    cloud[n][1] = cloud[n][2] = cloud[n - 1][1] = cloud[n - 1][2] = 1;

    for (int k = 1; k <= m; k++) {
        ll d, s;
        cin >> d >> s;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cloud[i][j]) {
                    mov(d, s, i, j);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cloud2[i][j]) {
                    arr[i][j]++;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cloud2[i][j]) {
                    ll r = i, c = j;
                    arr[r][c] += bool(arr[r + 1][c - 1]) + bool(arr[r + 1][c + 1]) + bool(arr[r - 1][c - 1]) + bool(arr[r - 1][c + 1]);
                }
            }
        }

        memset(cloud, 0, sizeof(cloud));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!cloud2[i][j] && arr[i][j] >= 2) {
                    cloud[i][j] = 1;
                    arr[i][j] -= 2;
                }
            }
        }

        memset(cloud2, 0, sizeof(cloud2));
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res += arr[i][j];
        }
    }
    cout << res;

    return 0;
}