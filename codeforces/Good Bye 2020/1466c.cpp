#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		
		int ans=0;
		for(int i=1;i<s.size();++i){
			if(i>0 && s[i]==s[i-1]) {
				ans++; s[i]='*';
			}
			else if(i>1 && s[i]==s[i-2]){
				ans++; s[i]='*';
			}
		}cout<<ans<<'\n';
	}
}
