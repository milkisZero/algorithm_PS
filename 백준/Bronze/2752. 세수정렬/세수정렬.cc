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

int arr[5];

int main() {
    fastio;
  
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}