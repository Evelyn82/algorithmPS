#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e9+1;
int main(){ 
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<int> a(n, 0);
        ll se = 0, so = 0;
        for (int i = 0; i < n; i++) { 
            cin >> a[i];
            if (i % 2 == 0) se += a[i];
            else so += a[i];
        }
        if (se >= so) {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) cout << (a[i] + a[i] % 2) << ' ';
                else cout << 2 << ' ';
            }
        }
        else{
            for (int i = 0; i < n; i++) {
                if (i % 2 != 0) cout << (a[i] + a[i] % 2) << ' ';
                else cout << 2 << ' ';
            }

        }
        cout << '\n';
    }
    return 0;
}
