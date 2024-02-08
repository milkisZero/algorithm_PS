#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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

    int n;
    cin >> n;

    unordered_map<string, vector<string>> m;
    unordered_map<string, int> ind;
    vector<string> res;

    while (n--) {
        string a, b;
        cin >> a >> b;
        m[a].push_back(b);
        if (ind.find(a) == ind.end())
            ind.insert({a, 0});
        if (ind.find(b) == ind.end())
            ind.insert({b, 0});
        ind[b]++;
    }

    priority_queue<string, vector<string>, greater<>> q;
    vector<string> v;
    for (auto iter = ind.begin(); iter != ind.end(); iter++) {
        if (iter->second == 0)
            q.push(iter->first);
    }

    while (!q.empty()) {
        string cur = q.top();
        q.pop();
        for (auto e : m[cur]) {
            if (--ind[e] == 0)
                v.push_back(e);
        }

        if (q.empty()) {
            for (auto e : v) {
                q.push(e);
            }
            v.clear();
        }

        res.push_back(cur);
    }

    if (res.size() != ind.size())
        cout << -1;
    else {
        for (auto e : res) {
            cout << e << '\n';
        }
    }

    return 0;
}