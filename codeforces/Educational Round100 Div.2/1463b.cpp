#include <iostream>
using namespace std;
using ll = long long;

ll arr[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		ll num, odd = 0, even = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if (i % 2 == 0) even += arr[i];
			else odd += arr[i];
		}

		if (odd <= even) {
			for (int i = 0; i < n; ++i) {
				if (i % 2 == 0) cout << arr[i] << ' ';
				else cout << 1 << ' ';
			}
		}
		else {
			for (int i = 0; i < n; ++i) {
				if (i % 2 != 0) cout << arr[i] << ' ';
				else cout << 1 << ' ';
			}
		}cout << '\n';
	}
}
