#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		
		ll sum=0, ret1=0, ret2=0;
		int m;
		for(int i=0;i<n;++i) {
			cin>>m;
			sum+=m;
      
			/*
			ret2+=m/k;
			if(m%k) ret2++;	
			*/
			ret2+=(m+k-1)/k;
		}
    
		/*
		ret1=sum/k;
		if(sum%k) ret1++;
		*/
		ret1=(sum+k-1)/k;
		cout<<ret1<<' '<<ret2<<'\n';
	}
}
