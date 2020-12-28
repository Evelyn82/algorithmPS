#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
 
		int sub = min(x, y), h = max(x, y), ans = 0;
		// 15ms
		if (sub == 0 && h > 0) ans = (h - 2) * 2 + 3;
		else {
			ans = sub * 2;
			h -= sub;
			if (h) ans += (h - 1) * 2 + 1;
		}cout << ans << '\n';
		
		
		/*
		31ms
	        if(sub == h) ans = sub * 2;
        	else {
            		ans = sub * 2;
           		h -= sub;
            		ans += (h - 1) * 2 + 1;
        	}cout << ans << '\n';
		*/
	}
}
