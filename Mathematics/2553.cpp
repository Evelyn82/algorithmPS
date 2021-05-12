#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

// TLE from 1e3 (decreasing)
const ll DIV=1e10;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin>>n;
	
	ll ret=1;
	for(int i=2;i<=n;++i){
		ret*=i;
		ret%=DIV;
		while(ret%10==0) ret/=10;
	}cout<<ret%10<<'\n';
}
