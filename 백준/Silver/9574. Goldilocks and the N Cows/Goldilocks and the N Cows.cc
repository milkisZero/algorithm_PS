#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, 0});
        vec.push_back({b, 1});
    }
    sort(vec.begin(), vec.end());

    int cnt = 0, val = n * x;
    for (int i = 0; i < vec.size(); i++) {
        if (!vec[i].second)
            val = val - x + y;
        else
            val = val - y + z;
        cnt = max(cnt, val);
    }

    cout << cnt;

    return 0;
}