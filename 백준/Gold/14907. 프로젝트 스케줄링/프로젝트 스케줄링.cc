#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<string> graph[28];
int node[28], val[28];

int func() {
    queue<string> q;
    for (int i = 0; i < graph[0].size(); i++) {
        q.push(graph[0][i]);
        val[graph[0][i][0] - 'A' + 1] = node[graph[0][i][0] - 'A' + 1];
    }

    int res = 0;
    while (!q.empty()) {
        string s = q.front();
        int cur = s[0] - 'A' + 1;
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            s = graph[cur][i];
            int child = s[0] - 'A' + 1;
            int k = node[child] + val[cur];
            val[child] = max(val[child], k);

            q.push(s);
        }

        if (graph[cur].empty())
            res = max(res, val[cur]);
    }

    return res;
}

int main() {
    fastio();

    string s;
    while (getline(cin, s)) {
        istringstream iss(s);

        string a, b, c;
        iss >> a >> b >> c;

        node[a[0] - 'A' + 1] = stoi(b);

        if (c == "")
            graph[0].push_back(a);

        for (int i = 0; i < c.size(); i++) {
            graph[c[i] - 'A' + 1].push_back(a);
        }
    }

    cout << func();

    return 0;
}