#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

const int MAXN = 3E4 + 1;
int candy[MAXN], dp[3001];
pii par[MAXN];
int findPar(int n) {
	if (par[n].first < 0) return n;
	return par[n].first = findPar(par[n].first);
}
void merge(int a, int b) {
	a = findPar(a);
	b = findPar(b);
	if (a != b) {
		if (par[a].first > par[b].first) swap(a, b);
		par[a].first += par[b].first;
		par[a].second += par[b].second;
		par[b].first = a;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> candy[i];
		par[i] = pii(-1, candy[i]);
	}
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		merge(a, b);
	}
	vector<pii> v;
	for (int i = 1; i <= N; ++i) if (par[i].first < 0) v.push_back(pii(-par[i].first, par[i].second));

	for (int i = 0; i < v.size(); ++i) {
		for (int j = K - 1; j >= v[i].first; --j) {
			dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
		}
	}
	int ans = 0;
	for (int i = 1; i < K; ++i) ans = max(ans, dp[i]);
	cout << ans << '\n';
}
