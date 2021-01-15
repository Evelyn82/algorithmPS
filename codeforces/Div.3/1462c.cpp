#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t, x;
	cin >> t;

	while (t--) {
		cin >> x;
		if (x < 10) cout << x << '\n';
		else if (x > 45) cout << -1 << '\n';
		else {
			string ret = "";
			int sub = 9;
			while (sub > 0) {
				if (x < 10 && x <= sub) {
					ret += (char)(x + '0');
					x = 0;
					break;
				}
				ret += (char)(sub + '0');
				x -= sub--;
			}
			if (x != 0) cout << -1 << '\n';
			else {
				sort(ret.begin(), ret.end());
				cout << stoi(ret) << '\n';
			}
		}
	}
}