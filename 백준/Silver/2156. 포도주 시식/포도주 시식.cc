#include <iostream>
#include <memory.h>
using namespace std;

int arr[10005];
int dp[10005];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {

		int first = -1, second= -1;
		if (i == 0) {
			dp[i] = arr[i];
		}
		else {
			// OOX 일 경우
			first = dp[i - 1];

			// OXO 일 경우
			if(i > 1)
				second = dp[i - 2] + arr[i];

			// i < 3 -> XOO 일 경우
			// i >= 3 -> OXOO 일 경우
			int third = -1;
			if (i < 3) {
				third = arr[i - 1] + arr[i];
			}
			else {
				third = dp[i - 3] + arr[i - 1] + arr[i];
			}
			first = max(first, third);

			dp[i] = max(first, second);
		}
	}

    cout << dp[n-1];

	return 0;
}