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

    unordered_map<string, int> um;
    vector<string> res;
    for (int i = 0; i < n + m; i++) {
        string s;
        cin >> s;
        if (um[s] > 0)
            res.push_back(s);
        else
            um[s] = 1;
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto e : res) {
        cout << e << '\n';
    }

    return 0;
}