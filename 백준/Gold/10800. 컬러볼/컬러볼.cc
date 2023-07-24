#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int idx, color, size;
} info;
info arr[200005];
int _color[200005];
int prefix[200005];
info res[200005];

int cmp(info a, info b) {
    if (a.size == b.size)
        return a.color < b.color;
    return a.size < b.size;
}

int cmp2(info a, info b) {
    return a.idx < b.idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        arr[i].idx = i;
        cin >> arr[i].color >> arr[i].size;
    }

    arr[0].size = 0;
    sort(arr, arr + n + 1, cmp);

    int tmp = 0, tmp2 = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i - 1].size == arr[i].size) {
            tmp += arr[i].size;
            if (arr[i - 1].color == arr[i].color)
                tmp2 += arr[i].size;
            else
                tmp2 = 0;
        }
        else {
            tmp = 0;
            tmp2 = 0;
        }
        prefix[i] += prefix[i - 1] + arr[i].size;
        _color[arr[i].color] += arr[i].size;

        res[i].size = prefix[i] - _color[arr[i].color] - tmp + tmp2;
        res[i].idx = arr[i].idx;
    }

    res[0].idx = 0;
    sort(res, res + n + 1, cmp2);

    for (int i = 1; i <= n; i++) {
        cout << res[i].size << '\n';
    }

    return 0;
}