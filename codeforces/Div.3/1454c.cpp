/*
4
2 1 3 1
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAXN = 2E5 + 1;
int prevIdx[MAXN];
map<int, int> ret;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		for (int i = 0; i <= n; ++i) prevIdx[i] = -1;
		ret.clear();

		for (int i = 0; i < n; ++i) {
			cin >> m;
			if (prevIdx[m] == -1) {
				if (i) ret[m] = 1;
				else ret[m] = 0;
			}
			else {
				if (prevIdx[m] + 1 < i) ret[m]++;
			}
			prevIdx[m] = i;
		}
		for (auto& r : ret) if (r.first != m) r.second++;
		int ans = MAXN;
		for (auto& r : ret) ans = min(ans, r.second);
		if (ans == MAXN) ans = 0;
		cout << ans << '\n';
	}
}
