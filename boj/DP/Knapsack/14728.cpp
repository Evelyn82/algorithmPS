#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN=101;
int time[MAXN], score[MAXN];
int d[10001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n,t; cin>>n>>t;
	
	for(int i=0;i<n;++i) cin>>time[i]>>score[i];
	
	for(int i=0;i<n;++i){
		for(int j=t;j>=time[i];--j){
			d[j]=max(d[j], d[j-time[i]]+score[i]);
		}
	}cout<<d[t]<<'\n';
}
