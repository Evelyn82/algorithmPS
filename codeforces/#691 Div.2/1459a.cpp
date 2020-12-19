#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string r, b;
		cin >> r >> b;

		int ret1 = 0, ret2 = 0;
		for (int i = 0; i < n; ++i) {
			if (r[i] > b[i]) ret1++;
			else if (r[i] < b[i])ret2++;
		}
		if (ret1 > ret2) cout << "RED\n";
		else if (ret1 < ret2) cout << "BLUE\n";
		else cout << "EQUAL\n";
	}
}
