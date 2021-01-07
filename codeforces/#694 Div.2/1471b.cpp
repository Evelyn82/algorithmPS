#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN=1e5+1;
int a[MAXN], b[MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	while(t--){
		int n,x; cin>>n>>x;
		
		ll sum=0;
		for(int i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
			b[i]=a[i];
		}
		
		bool flag=false;
		while(1){
			for(int i=0;i<n;++i){
				if(b[i]%x==0){
					sum+=a[i];
					b[i]/=x;
				}
				else{
					flag=true;
					break;
				}
			}if(flag) break;
		}cout<<sum<<'\n';
	}
}
