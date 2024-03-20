#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 100005

int arr[MAX], ind[MAX], res[MAX];

void recur(int x) {
    if (res[arr[x]] != -1)
        return;
    res[arr[x]] = !res[x];
    recur(arr[x]);
}

int main() {
    fastio;

    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m + n; i++) {
        cin >> arr[i];
        if (i <= m)
            arr[i] += m;
        ind[arr[i]]++;
    }

    fill(res, res + MAX, -1);

    queue<int> pq;
    for (int i = 1; i <= m + n; i++) {
        if (!ind[i]) {
            pq.push(i);
            res[i] = 1;
        }
    }

    while (!pq.empty()) {
        int x = pq.front();
        pq.pop();
        ind[x] = -1;

        if (res[arr[x]] == -1) {
            int k = arr[x];
            ind[k] = -1;
            ind[arr[k]]--;
            if (ind[arr[k]] == 0) {
                ind[arr[k]] = -1;
                res[arr[k]] = 1;
                pq.push(arr[k]);
            }
        }
        res[arr[x]] = 0;
    }

    for (int i = 1; i <= m + n; i++) {
        if (res[i] == -1) {
            res[i] = 1;
            recur(i);
        }
    }

    for (int i = 1; i <= m + n; i++) {
        cout << res[i];
        if (i == m)
            cout << '\n';
    }

    return 0;
}