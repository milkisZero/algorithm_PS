#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <map>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v2[i] = v[i];
    }
    sort(v.begin(), v.end());

    map<vector<int>, double> m;
    vector<vector<int>> perm;

    do {
        m[v] = 0;
        perm.push_back(v);
    } while (next_permutation(v.begin(), v.end()));

    for (auto e : perm) {
        double num = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (e[i] < e[j])
                    continue;
                swap(e[i], e[j]);
                num += m[e] + 1;
                cnt++;
                swap(e[i], e[j]);
            }
        }

        if (cnt)
            m[e] = num / cnt;
        if (e == v2)
            break;
    }

    cout << fixed;
    cout.precision(6);

    cout << m[v2];

    return 0;
}