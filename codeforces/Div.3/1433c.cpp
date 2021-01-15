#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 3E5 + 1;
int arr[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, start = MAXN, ans = -1;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if (start > arr[i]) {
				start = arr[i];
				ans = i;
			}
		}
		int idx = ans, sz1 = start + 1;
		int ans1 = -1;
		// left
		while (idx - 1 >= 0) {
			if (arr[idx - 1] >= sz1) { ans1 = idx - 1; sz1 = arr[idx - 1] + 1; }
			idx--;
		}idx = ans;
		while (idx + 1 < n) {
			if (arr[idx + 1] >= sz1) { ans1 = idx + 1; sz1 = arr[idx + 1] + 1; }
			idx++;
		}
		// right
		int sz2 = start + 1, ans2 = -1;
		idx = ans;
		while (idx - 1 >= 0) {
			if (arr[idx - 1] >= sz2) { ans2 = idx - 1; sz2 = arr[idx - 1] + 1; }
			idx--;
		}
		idx = ans;
		while (idx + 1 < n) {
			if (arr[idx + 1] >= sz2) { ans2 = idx + 1; sz2 = arr[idx + 1] + 1; }
			idx++;
		}

		if (ans1 == -1 && ans2 == -1) cout << -1;
		else if (ans1 != -1 && ans2 != -1) {
			if (sz1 > sz2)  cout << ans1 + 1;
			else cout << ans2 + 1;
		}
		else {
			if (ans1 == -1) cout << ans2 + 1;
			else cout << ans1 + 1;
		}cout << '\n';
	}
}
