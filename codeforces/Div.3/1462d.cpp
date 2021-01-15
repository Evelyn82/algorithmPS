#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[3001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}

		for (int i = n; i > 0; --i) {
			// Division to Equal numbers
			if (sum % i == 0) {
				int tmp = 0, share = sum / i;
				bool flag = true;

				for (int j = 1; j <= n; ++j) {
					tmp += arr[j];
					if (tmp > share) {
						flag = false;
						break;
					}
					else if (tmp == share) tmp = 0;
				}
				if (flag) {
					cout << n - i << '\n';
					break;
				}
			}
		}
	}
}
