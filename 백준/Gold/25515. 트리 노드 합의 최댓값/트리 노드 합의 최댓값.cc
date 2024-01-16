#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> v[100005];
int val[100005];
int visited[100005];

ll dfs(int cur) {
    visited[cur] = 1;

    ll sum = 0;
    for (int i = 0; i < v[cur].size(); i++) {
        if (visited[v[cur][i]] == 0) {
            ll tmp = dfs(v[cur][i]);
            if (tmp > 0)
                sum += tmp;
        }
    }

    sum += val[cur];

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        val[i] = a;
    }

    cout << dfs(0);

    return 0;
}