#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using plc = pair<ll, char>;

plc alp[27];
string s[55];

int cmp(plc a, plc b) {
    return a.first > b.first;
}

int main() {
    fastio;

    for (char i = 'A'; i <= 'Z'; i++) {
        alp[i - 'A'] = {0, i};
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int leng = s[i].length();
        for (int j = 0; j < leng; j++) {
            alp[s[i][j] - 'A'].first += pow(10, leng - j - 1);
        }
    }

    sort(alp, alp + 27, cmp);

    map<char, int> m;
    int idx = 0;
    for (int i = 9; i >= 0; i--, idx++) {
        m[alp[idx].second] = i;
    }

    for (int i = idx - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (s[j][0] == alp[i].second && m[alp[i].second] == 0) {
                swap(m[alp[i].second], m[alp[i - 1].second]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].length(); j++) {
            s[i][j] = m[s[i][j]] + '0';
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += stoll(s[i]);
    }

    cout << sum;

    return 0;
}