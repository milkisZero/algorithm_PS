#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 100002

int d[MAX];

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    fill(d, d + MAX - 1, INF);

    priority_queue<pi> pq;
    d[n] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        auto [t, x] = pq.top();
        t = -t;
        pq.pop();
        if (t == d[x]) {
            if (t + 1 <= d[k]) {
                if (x + 1 < MAX && d[x + 1] > t + 1) {
                    d[x + 1] = t + 1;
                    pq.push({-(t + 1), x + 1});
                }
                if (x - 1 >= 0 && d[x - 1] > t + 1) {
                    d[x - 1] = t + 1;
                    pq.push({-(t + 1), x - 1});
                }
            }
            if (x * 2 < MAX && d[x * 2] > t && t < d[k]) {
                d[x * 2] = t;
                pq.push({-t, x * 2});
            }
        }
    }

    cout << d[k];

    return 0;
}