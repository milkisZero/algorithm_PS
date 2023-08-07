#include <iostream>
#include <vector>
using namespace std;

vector<int> node[55];
int visited[55];
int visited2[55];
int cnt, k;

void delete_graph(int cur) {
    visited2[cur] = 1;

    for (int i = 0; i < node[cur].size(); i++) {
        if (visited2[node[cur][i]] == 0)
            delete_graph(node[cur][i]);
    }
}

void dfs(int cur) {
    visited[cur] = 1;

    int qq = 0;
    for (int i = 0; i < node[cur].size(); i++) {
        if (visited2[node[cur][i]]) {
            qq++;
        }
        else if (visited[node[cur][i]] == 0)
            dfs(node[cur][i]);
    }

    if (node[cur].size() - qq == 0)
        cnt++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int root;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == -1)
            root = i;
        else
            node[tmp].push_back(i);
    }

    cin >> k;
    delete_graph(k);
    dfs(root);

    if (k == root)
        cnt = 0;

    cout << cnt;

    return 0;
}