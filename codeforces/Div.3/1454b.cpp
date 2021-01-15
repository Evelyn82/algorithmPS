#include <iostream>
#include <set>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAXN = 2e5 + 1;
int d[MAXN], idx[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(d, 0, sizeof(d));
		int num;
		for (int i = 1; i <= n; ++i) {
			cin >> num;
			d[num]++;
			idx[num] = i;
		}

		int ans = -1;
		for (int i = 1; i <= n; ++i) if (d[i] == 1) { ans = idx[i]; break; }
		cout << ans << '\n';
	}
}