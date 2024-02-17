#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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

    int p[n], visited[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    fill(visited, visited + n, -1);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            int idx = i;
            while (visited[idx] != 1) {
                visited[idx] = 1;
                idx = p[idx];
            }
            cnt++;
        }
    }

    if (cnt == 1)
        cout << 0;
    else
        cout << cnt;

    return 0;
}