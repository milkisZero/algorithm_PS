#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    deque<char> dq;
    dq.push_back(s[0]);

    for (int i = 1; i < s.length(); i++) {
        char f = dq[0];
        if (f < s[i])
            dq.push_back(s[i]);
        else
            dq.push_front(s[i]);
    }

    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i];
    }

    return 0;
}