#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 501
int n, arr[MAXN][MAXN], d[MAXN][MAXN];
int dx[]={-1, 1, 0, 0}, dy[]={0, 0, 1, -1};
int solve(int x, int y){
	int& ref=d[x][y];
	if(ref!=-1) return ref;
	ref=1;
	for(int i=0;i<4;++i){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=n) continue;
		if(arr[nx][ny]>arr[x][y]) ref=max(ref, solve(nx, ny)+1);
	}
	return ref;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>arr[i][j];
			d[i][j]=-1;
		}
	}
	
	int ret=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			ret=max(ret, solve(i, j));
		}
	}cout<<ret<<'\n';
}
