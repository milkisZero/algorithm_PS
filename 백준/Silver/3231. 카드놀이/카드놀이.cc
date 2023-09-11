#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> vec(n + 1);
    vector<ll> vec2(n + 1);
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        vec2[vec[i]] = i;
    }

    for (int i = 0; i <= n - 1; i++) {
        if (vec2[i] > vec2[i + 1])
            cnt++;
    }

    cout << cnt;

    return 0;
}