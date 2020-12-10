#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAXN = 2E5 + 1;
vector<vector<int>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear(); v.resize(n + 1);

		for (int i = 0; i < n; ++i) {
			cin >> m;
			v[m].push_back(i);
		}

		int ans = MAXN, sz;
		for (int i = 1; i <= n; ++i) {
			if (v[i].empty()) continue;
			sz = 0;
			for (int j = 0; j < v[i].size(); ++j) {
				if (j == 0) if (v[i][j] != 0) sz++; 
				if (j == v[i].size() - 1) if (i != m) sz++;
				if (j < v[i].size() - 1 && v[i][j] + 1 < v[i][j + 1]) sz++;
			}
			ans = min(ans, sz);
		}cout << ans << '\n';
	}
}