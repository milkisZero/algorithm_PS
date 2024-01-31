#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<pi> cnt;

int main() {
    fastio();

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int res = 0;
        int start = -1;
        for (int i = 0; i < s.length(); i++) {
            res += min(abs(s[i] - 'A'), abs('Z' - s[i] + 1));

            if (s[i] == 'A' && start == -1)
                start = i;
            else if (s[i] != 'A' && start != -1) {
                cnt.push_back({start, i - 1});
                start = -1;
            }
        }
        if (start != -1)
            cnt.push_back({start, s.length() - 1});

        int mini = s.length() - 1;
        for (auto &e : cnt) {
            int a = e.first - 1, b = s.length() - e.second - 1;
            a < 0 ? a = 0 : a;
            mini = min(mini, min(a * 2 + b, a + b * 2));
        }

        cout << res + mini << '\n';
        cnt.clear();
    }

    return 0;
}