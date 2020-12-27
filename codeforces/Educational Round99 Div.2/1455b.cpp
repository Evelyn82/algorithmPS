#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;

		int sum = 0, ans;
		for (int i = 1;; ++i) {
			sum += i;
			//sum = i * (1 + i) / 2;

			if (sum < x) continue;
			ans = i;
			if (sum - 1 == x) ans++;
			break;
		}cout << ans << '\n';
	}
}
