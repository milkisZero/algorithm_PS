#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int z;
    cin >> z;

    while (z--) {
        int n;
        cin >> n;

        set<pii, greater<>> pq;
        vector<int> sp[n + 5], ep[n + 5];
        vector<pii> arr(n + 5);

        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            arr[i] = {a, b};

            int s = i - a, e = i + a;
            s = s < 1 ? 1 : s;
            e = e > n ? n : e;
            sp[s].push_back(i);
            ep[e].push_back(i);
        }

        ll res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < sp[i].size(); j++) {
                pq.insert({arr[sp[i][j]].second, sp[i][j]});
            }

            if (pq.size() >= 3) {
                ll tmp = 0, j = 0;
                for (auto iter = pq.begin(); iter != pq.end() && j < 3; iter++, j++) {
                    tmp += iter->first;
                }
                res = max(res, tmp);
            }

            for (int j = 0; j < ep[i].size(); j++) {
                pq.erase({arr[ep[i][j]].second, ep[i][j]});
            }
        }

        cout << res << '\n';
    }

    return 0;
}