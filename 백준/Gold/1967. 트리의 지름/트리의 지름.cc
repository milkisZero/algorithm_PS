#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> node[10005];
int visited[10005];
int res = -1;

int dfs(int cur) {
    visited[cur] = 1;

    int tmp = 0, max1 = 0, max2 = 0, val;
    for (int i = 0; i < node[cur].size(); i++) {
        int next = node[cur][i].first;
        if (visited[next] == 0) {
            val = dfs(next) + node[cur][i].second;
            tmp = max(val, tmp);
        }

        if (max1 < val) {
            if (max1 > max2)
                max2 = max1;
            max1 = val;
        }
        else if (max2 < val)
            max2 = val;
    }

    res = max(res, max1 + max2);

    if (tmp < 0)
        return 0;
    else
        return tmp;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        node[a].push_back(make_pair(b, c));
    }

    dfs(1);

    cout << res;

    return 0;
}