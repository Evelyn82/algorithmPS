#include <iostream>
using namespace std;

int arr[301];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> arr[i];

		int sz = n / 2;
		for (int i = 0; i < sz; ++i) {
			cout << arr[i] << ' ';
			cout << arr[n - i - 1] << ' ';
		}
		if (n % 2) cout << arr[sz];
		cout << '\n';
	}
}
