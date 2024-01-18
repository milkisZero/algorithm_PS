#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    while (1) {
        int num[88] = {0};

        ll n, m;
        cin >> n >> m;

        if (!n && !m)
            break;

        for (int i = 0; i < n; i++) {
            cin >> num[i];
            num[i]--;
        }

        string s;
        cin.ignore();
        getline(cin, s);

        int visited[n + 1] = {0};
        fill(visited, visited + n, -1);

        vector<int> circ[88];
        int id[88] = {0};

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                int idx = i;
                while (1) {
                    if (visited[idx] != -1)
                        break;
                    visited[idx] = i;
                    circ[i].push_back(idx);
                    id[idx] = circ[i].size() - 1;
                    idx = num[idx];
                }
                visited[i] = i;
            }
        }

        string res = s;
        for (int i = 0; i < n; i++) {
            int k = visited[i], vsize = circ[k].size();
            int cur = (id[i] + m % vsize);
            res[circ[k][cur % vsize]] = s[i];
        }

        cout << res << '\n';
    }

    return 0;
}