#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

typedef struct data {
    int val, r, c;
} group;
vector<group> vec[4];

int n, q;
pair<int, int> info[4] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int res[1005][1005];
int index[1005][1005];
int a1, a2, b1, b2;

int s_command(int i, int q1, int q2) {
    int dif_r = vec[i][1].r - vec[i][0].r;
    int dif_c = vec[i][1].c - vec[i][0].c;

    int tmp1 = (q1 + dif_r) % n;
    tmp1 = tmp1 == 0 ? n : tmp1;
    if (q1 + dif_r < 0)
        tmp1 = q1 + dif_r + n;
    int tmp2 = (q2 + dif_c) % n;
    tmp2 = tmp2 == 0 ? n : tmp2;
    if (q2 + dif_c < 0)
        tmp2 = q2 + dif_c + n;

    return index[tmp1][tmp2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> q;

    vec[0].push_back({1, 1, 1});
    vec[1].push_back({2, 1, 2});
    vec[2].push_back({1 + n, 2, 1});
    vec[3].push_back({2 + n, 2, 2});

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!(i % 2) && j % 2) {
                vec[0].push_back({i * n + j, i + 1, j});
                index[i + 1][j] = vec[0].size() - 1;
            }
            else if (!(i % 2) && !(j % 2)) {
                vec[1].push_back({i * n + j, i + 1, j});
                index[i + 1][j] = vec[1].size() - 1;
            }
            else if (i % 2 && j % 2) {
                vec[2].push_back({i * n + j, i + 1, j});
                index[i + 1][j] = vec[2].size() - 1;
            }
            else {
                vec[3].push_back({i * n + j, i + 1, j});
                index[i + 1][j] = vec[3].size() - 1;
            }
        }
    }

    while (q--) {
        string str;
        cin >> str;

        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        if (str == "S")
            cin >> a1 >> a2 >> b1 >> b2;

        for (int i = 0; i < 4; i++) {
            if ((str == "RO" && info[i].first == -1) || (str == "RE" && info[i].first == 1)) {
                vec[i][0].c = (vec[i][0].c + 1) % n;
                vec[i][0].c = vec[i][0].c == 0 ? n : vec[i][0].c;
                if (vec[i][0].c % 2)
                    info[i].second = -1;
                else
                    info[i].second = 1;
            }
            else if ((str == "CO" && info[i].second == -1) || (str == "CE" && info[i].second == 1)) {
                vec[i][0].r = (vec[i][0].r + 1) % n;
                vec[i][0].r = vec[i][0].r == 0 ? n : vec[i][0].r;
                if (vec[i][0].r % 2)
                    info[i].first = -1;
                else
                    info[i].first = 1;
            }
            else if (str == "S") {
                if (abs(a1 - vec[i][0].r) % 2 == 0 && abs(a2 - vec[i][0].c) % 2 == 0) {
                    s1 = i;
                    s2 = s_command(i, a1, a2);
                }
                if (abs(b1 - vec[i][0].r) % 2 == 0 && abs(b2 - vec[i][0].c) % 2 == 0) {
                    s3 = i;
                    s4 = s_command(i, b1, b2);
                }
            }
        }

        if (str == "S") {
            swap(vec[s1][s2].val, vec[s3][s4].val);
        }
    }

    for (int i = 0; i < 4; i++) {
        int row = vec[i][0].r, col = vec[i][0].c;
        for (int j = 1; j < vec[i].size(); j++) {
            res[row][col] = vec[i][j].val;
            col = (col + 2) % n;
            col = col == 0 ? n : col;

            if (res[row][col]) {
                row = (row + 2) % n;
                row = row == 0 ? n : row;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}