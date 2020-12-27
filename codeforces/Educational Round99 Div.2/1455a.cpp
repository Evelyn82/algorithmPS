#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	string n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << n.length() << '\n';
	}
}
