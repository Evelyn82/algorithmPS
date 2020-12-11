#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n;
		
		int prev = -1, ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> m;
			if (m == 1) {
				if (prev != -1) ans += abs(i - prev - 1);
				prev = i;
			}
		}
		cout << ans << '\n';
	}
}