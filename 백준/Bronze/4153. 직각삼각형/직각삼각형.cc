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

int main() {
    fastio();

    while (1) {
        int arr[4];
        cin >> arr[0] >> arr[1] >> arr[2];

        if (!arr[0] && !arr[1] && !arr[2])
            break;

        sort(arr, arr + 3);

        if (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0])
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}