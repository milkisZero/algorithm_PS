#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> um1;
    unordered_map<string, string> um2;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        um1[s] = to_string(i);
        um2[to_string(i)] = s;
    }

    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (um1.find(s) != um1.end())
            cout << um1[s] << '\n';
        else
            cout << um2[s] << '\n';
    }

    return 0;
}