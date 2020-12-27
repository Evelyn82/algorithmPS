#include <iostream>
using namespace std;
 
int arr[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
 
	int t, sum;
	cin >> t;
	while (t--) {
		sum = 0;
		for (int i = 0; i < 3; ++i) {
			cin >> arr[i]; 
			sum += arr[i];
		}
		if (sum < 9 || sum % 9) cout << "NO\n";
		else {
			int share = sum / 9;
			bool flag = false;
			for (int i = 0; i < 3; ++i) {
				if (arr[i] < share) flag = true;
			}
			if (flag) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}
