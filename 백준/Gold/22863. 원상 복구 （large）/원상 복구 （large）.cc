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

vector<ll> s, d;

int main() {
    fastio();

    ll n, k, tmp;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        s.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        d.push_back(tmp - 1);
    }

    ll visited[n + 1], circ_idx[n + 1] = {0};
    fill(visited, visited + n, -1);
    vector<vector<ll>> circ(n + 1);

    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            ll idx = i;
            while (1) {
                if (visited[idx] != -1)
                    break;
                visited[idx] = i;
                circ[i].push_back(idx);
                circ_idx[idx] = circ[i].size() - 1;
                idx = d[idx];
            }
        }
    }

    ll res[n + 1];
    for (int i = 0; i < n; i++) {
        ll head = visited[i];
        ll csize = circ[head].size();
        ll num = circ[head][(circ_idx[i] + k) % csize];
        res[num] = s[i];
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}