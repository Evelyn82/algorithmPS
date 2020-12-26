#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int t; cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;
		cout<<x-1<<' '<<y<<'\n';
		
		// Get your score optimized for you
		/*
		WA Code
		if(x == y) cout<<0<<' '<<1<<'\n';
		else if(x > y) cout<<x-y<<' '<<1<<'\n';
		else cout<<0<<' '<<y-x+1<<'\n';
		*/
	}
}
