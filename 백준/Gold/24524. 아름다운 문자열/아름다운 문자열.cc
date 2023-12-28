#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    deque<int> alpha[27];

    for (int i = 0; i < s.length(); i++) {
        alpha[s[i] - 'a'].push_back(i);
    }

    int check = 0, cnt = 0;
    while (!check && !alpha[t[0] - 'a'].empty()) {
        for (int i = 0; i < t.length(); i++) {
            if (alpha[t[i] - 'a'].empty()) {
                check = 1;
                break;
            }
        }
        if (check)
            break;

        for (int i = 1; i < t.length() && !check; i++) {
            int prev = alpha[t[i - 1] - 'a'].front();

            while (prev > alpha[t[i] - 'a'].front()) {
                alpha[t[i] - 'a'].pop_front();
                if (alpha[t[i] - 'a'].empty()) {
                    check = 1;
                    break;
                }
            }
        }
        if (check)
            break;
        else
            cnt++;

        for (int i = 0; i < t.length(); i++) {
            if (alpha[t[i] - 'a'].empty()) {
                check = 1;
                break;
            }
            alpha[t[i] - 'a'].pop_front();
        }
    }

    cout << cnt;

    return 0;
}