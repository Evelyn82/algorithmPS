#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		bool flag = (n % 2) ? true : false;
		int half = n / 2;
		for (int i = 0; i < n; ++i) {
			if (flag && half == i) {
				cout << n - (i + 1) << ' ';
				cout << n - i << ' ';
				++i;
			}
			else cout << n - i << ' ';
		}cout << '\n';
	}
}