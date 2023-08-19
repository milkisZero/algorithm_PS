#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int arr[5000005];
deque<pair<int, int>> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        while (!dq.empty()) {
            if (dq.back().second > arr[i])
                dq.pop_back();
            else
                break;
        }
        dq.push_back({i, arr[i]});

        if (!dq.empty() && i - dq.front().first + 1 > l) {
            dq.pop_front();
        }

        cout << dq.front().second << ' ';
    }

    return 0;
}