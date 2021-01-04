#include <iostream>
#include <string>
using namespace std;


char c[]={'a', 'b', 'c'};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		string s="";
	
		int i;
		for(i=0;i<k;;++i) s+='a';
		
	   int	j=1;
		for(;i<n;++i){
			s+=c[j];
			j=(j+1)%3;
		}cout<<s<<'\n';
	}
}
