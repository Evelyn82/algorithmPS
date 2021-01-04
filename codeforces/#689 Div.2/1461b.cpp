#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long ll;

const int MAXN=510;
char arr[MAXN][MAXN];
ll d[MAXN][MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j) cin>>arr[i][j];
		
		for(int i=0;i<MAXN;++i) for(int j=0;j<MAXN;++j) d[i][j]=0;
		
		ll ans=0;	
		for(int i=n;i>0;--i){
			for(int j=1;j<=m;++j) {
				if(arr[i][j]!='*')	continue;
				
				if(i!=n && arr[i+1][j]!='*') d[i][j]=1;
				else d[i][j]=min(d[i+1][j-1], d[i+1][j+1])+1;
				ans+=d[i][j];		
			}
		}
		cout<<ans<<'\n';
	}
}
