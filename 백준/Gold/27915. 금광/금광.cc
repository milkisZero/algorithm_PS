#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> arr[100006];
int visited[100006];
int depth[100006];

void dfs(int cur, int d) {
    visited[cur] = 1;
    depth[d]++;

    for (int i = 0; i < arr[cur].size(); i++) {
        if (visited[arr[cur][i]] == 0)
            dfs(arr[cur][i], d + 1);
    }
}

int main() {
    fastio();

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp].push_back(i);
    }

    dfs(1, 1);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n && depth[i] != 0; j += 2) {
            if (depth[j] > depth[i]) {
                depth[j] -= depth[i];
                cnt += depth[i];
                depth[i] = 0;
            }
            else {
                depth[i] -= depth[j];
                cnt += depth[j];
                depth[j] = 0;
            }
        }
        if (depth[i])
            cnt += depth[i];
    }

    cout << cnt;

    return 0;
}