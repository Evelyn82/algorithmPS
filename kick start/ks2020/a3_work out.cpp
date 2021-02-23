#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int solve(int N, int K, vector<int> M) {
	int low = 0;
	int high = 1e9;
	while (low + 1 < high) {
		int mid = (low + high) / 2; 
		int cnt = 0;
		for (int i = 1; i < M.size(); i++) {
			int diff = M[i] - M[i - 1];
			cnt += (diff - 1) / mid;
		}
		if (cnt <= K) high = mid;
		else low = mid; 
	}
	return high;
}

int main() {
	int T;
	cin >> T;
	int N, K;
	for (int c = 1; c <= T; c++) {
		cin >> N >> K;
		vector<int> M(N, 0);
		for (int i = 0; i < N; i++) cin >> M[i];
		cout << "Case #" << c << ": " << solve(N, K, M) << endl;
	}

	return 0;
}
