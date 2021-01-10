#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX=1024;
int arr[MX+1][MX+1], fw[MX+1][MX+1];
int n;
void build()
{
	for(int x=1;x<=n;++x)
		for(int y=1;y<=n;++y){
			int y2=y+(y&-y);
			if(y2<=n) fw[x][y2]+=fw[x][y];
		}
	for(int y=1;y<=n;++y)
		for(int x=1;x<=n;++x){
			int x2=x+(x&-x);
			if(x2<=n) fw[x2][y]+=fw[x][y];
		}
}
void update(int x,int y,int num)
{
	for(;x<=n;x+=x&-x)
		for(int y1=y;y1<=n;y1+=y1&-y1)
			fw[x][y1]+=num;
}
int query(int x,int y)
{
	int sum=0;
	for(;x>0;x-=x&-x)
		for(int y1=y;y1>0;y1-=y1&-y1)
			sum+=fw[x][y1];
	return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	  int m; cin>>n>>m;
	  for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) {cin>>arr[i][j]; fw[i][j]=arr[i][j];}
  	build();
	
	  int w, x, y, x2, y2;
  	while(m--){
      cin>>w>>x>>y;
		  if(w){
		  	cin>>x2>>y2;
       	int ret=query(x2,y2);
        ret-=query(x2,y-1);
        ret-=query(x-1,y2);
        ret+=query(x-1,y-1);
        cout<<ret<<'\n';
		  }
		  else{
			  cin>>x2;
			  update(x,y,x2-arr[x][y]);
			  arr[x][y]=x2;
	  	}
	  }
}
