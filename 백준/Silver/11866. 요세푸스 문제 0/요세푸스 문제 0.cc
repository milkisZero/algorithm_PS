#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << '<';
    for (int cnt = 1; !q.empty(); cnt++) {
        int tmp = q.front();
        q.pop();

        if (cnt == k) {
            cnt = 0;
            cout << tmp;
            if (!q.empty())
                cout << ", ";
        }
        else
            q.push(tmp);
    }
    cout << '>';

    return 0;
}