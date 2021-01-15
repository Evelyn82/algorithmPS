#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		if (s.substr(n - 4) == "2020") cout << "YES\n";
		else if (s.substr(0, 4) == "2020") cout << "YES\n";
		else if (s.substr(0, 3) == "202" && s.back() == '0') cout << "YES\n";
		else if (s.substr(0, 2) == "20" && s.substr(n - 2) == "20") cout << "YES\n";
		else if (s[0] == '2' && s.substr(n - 3) == "020") cout << "YES\n";
		else cout << "NO\n";
	}
}