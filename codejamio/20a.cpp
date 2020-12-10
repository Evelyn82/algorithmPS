#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t; cin >> t;
	string s;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> s;
		int up = 0, lw = 0, ans = 0;
		for (char& c : s) {
			if (c == 'I') up++;
			else if (c == 'i') lw++;
			else if (c == 'O') {
				if (up) {
					up--;
					ans++;
				}
				else lw--;
			}
			else {
				if (lw) lw--;
				else up--;
			}
		}
		cout << "Case #" << tc << ": " << ans << '\n';
	}
}