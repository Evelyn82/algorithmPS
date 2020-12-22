#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int dp[101][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int N, K; cin >> N >> K;
  
	vector<pair<int, int>> v(N + 1);
	v[0].first = v[0].second = 0;
	for (int i = 1; i <= N; ++i) cin >> v[i].first >> v[i].second;
	memset(dp, 0, sizeof(dp));

	for (int j = 0; j <= K; ++j) {
		for (int i = 1; i <= N; ++i) {
			dp[i][j] = dp[i - 1][j];
			if (j >= v[i].first) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].first] + v[i].second);
			}
		}
	}cout << dp[N][K] << '\n';
}
