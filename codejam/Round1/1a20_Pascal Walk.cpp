#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Path{
    bool flag;
    int x, y;
    Path(){}
    Path(bool _flag, int _x, int _y):flag(_flag), x(_x), y(_y){}
};
int pascal[51][51];
pair<int,int> pattern[]={{1, 0}, {0, 1}, {1,1}, {0, -1}};
void init(){
    for(int i=1;i<32;++i){
        for(int j=1;j<=i;++j){
            if(j==1 || j==i) pascal[i][j]=1;
            else pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
    }
}
void solve(int n){
    vector<Path> v;
    v.push_back(Path(true, 1, 1));
    
    int sum=1, idx=-1;
    while(sum<n){
        int nx=v.back().x, ny=v.back().y;
        idx=(idx+1)%4;
        nx+=pattern[idx].first; ny+=pattern[idx].second;
        v.push_back(Path(true, nx, ny));
        sum+=pascal[nx][ny];
    }
    // del
    int diff=sum-n;
    for(int i=(int)v.size()-1;i>=0;--i){
        if(pascal[v[i].x][v[i].y]<=diff) {
            v[i].flag=false;
            diff-=pascal[v[i].x][v[i].y];
        }if(diff==0) break;
    }
    for(Path i : v) if(i.flag==true) cout<<i.x<<' '<<i.y<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    init();
    for(int tc=1;tc<=t;++tc){
        int n; cin>>n;
        cout<<"Case #"<<tc<<":\n";
        solve(n);
        // 2^30=1,073.741,824 -> x<=31
    }
}
