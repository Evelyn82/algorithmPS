#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAXA = 1E5 + 1;
map<int, int> cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cnt.clear();
		vector<int> v(n);
		for (int& i : v) {
			cin >> i;
			cnt[i]++;
		}
		 
		int ans = 0;
		while (cnt.size() != 1) {
			int std = cnt.begin()->first;
			int sz = v.size();
			for (int i = sz - 1; i >= 0; --i) {
				if (v[i] == std) {
					int left = (i - 1 >= 0) ? v[i - 1] : -1;
					int right = (i + 1 < sz) ? v[i + 1] : -1;
					
					if (left == -1 || right == -1) {
						if (left == -1) {
							if (--cnt[right] == 0) cnt.erase(right);
							v[i + 1] += v[i];
							cnt[v[i + 1]]++;
						}
						if (right == -1) {
							if (--cnt[left] == 0) cnt.erase(left);
							v[i - 1] += v[i];
							cnt[v[i - 1]]++;
						}
					}
					else {
						if (left <= right) {
							if (--cnt[left] == 0) cnt.erase(left);
							v[i - 1] += v[i];
							cnt[v[i - 1]]++;
						}
						else {
							if (--cnt[right] == 0) cnt.erase(right);
							v[i + 1] += v[i];
							cnt[v[i + 1]]++;
						}
					}
					if (--cnt[v[i]] == 0) cnt.erase(v[i]);
					v.erase(v.begin() + i);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}
