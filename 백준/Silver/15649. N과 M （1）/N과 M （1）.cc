// #재귀 #백트래킹
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
int visited[9];

void recur(string s, int p, int m) {
    if (s.length() > 0)
        s = s + ' ';
    string v = s;
    if (m == 0) {
        cout << v << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;

        v = s + to_string(i);
        visited[i] = 1;
        recur(v, i, m - 1);
        v = s;
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    recur("", 1, m);

    return 0;
}