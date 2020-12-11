#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t, x;
	cin >> t;
	while (t--) {
		cin >> x;
		string s = to_string(x);

		int ans = 1 + 2 + 3 + 4;
		ans *= (int)(s[0] - '0') - 1;
		for (int i = 1, j = 0; j < s.length(); ++i, ++j) {
			ans += i;
		}cout << ans << '\n';
	}
}