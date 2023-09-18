#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> visited(n + 2, 0);
    int res = 0;
    for (int i = 0; i < k; i++) {
        int a, b;
        string as, bs;
        cin >> a >> b >> as >> bs;

        visited[a] = visited[b] = 1;

        if (as == bs) {
            if (m.find(as) != m.end() && m[as] == 0)
                res--;
            else if (m.find(as) != m.end() && m[as] > 0)
                m[as] = 0;
            continue;
        }

        if (m.find(as) == m.end())
            m.insert({as, a});
        else if (m[as] != a && m[as] != 0) {
            res++;
            m[as] = 0;
        }

        if (m.find(bs) == m.end())
            m.insert({bs, b});
        else if (m[bs] != b && m[bs] != 0) {
            res++;
            m[bs] = 0;
        }
    }

    int cnt = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            cnt++;
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > 0)
            cnt2++;
    }

    if (cnt2 == 0 && cnt == 2)
        res++;
    else if (cnt == cnt2)
        res += cnt2;

    cout << res;

    return 0;
}