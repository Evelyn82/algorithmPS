#include <iostream>
#include <algorithm>
#include <vector>
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

// 2^30=1,073,741,824 -> 2^(31-1) : 31row
const int MXN=32;

using ll=long long;
using pii=pair<int,int>;
using vpii=vector<pii>;
using vll=vector<ll>;

int pascal[MXN][MXN];
ll pSum[MXN*2];
vpii path;
void init(){
    for(int i=0;i<MXN;++i){
        for(int j=0;j<=i;++j){
            if(j==0||i==j) pascal[i][j]=1;
            else pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
    }
    
    path.push_back(make_pair(0,0));
    pSum[0]=1;
    int x=1, y=0, idx=1;
    while(1){
        path.push_back(make_pair(x,y));
        pSum[idx]=pSum[idx-1]+pascal[x][y];
        if(pSum[idx]>1e9) break;
        if(idx&1){
            // deleteable
            if(x&1) y++;
            else y--;
        }
        else{
            if(x&1) y++;
            x++;
        }idx++;
    }
}
int main(){
    fastio;
    init();
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        int n; cin>>n;
        cout<<"Case #"<<tc<<":\n";
        
        auto lwr=lower_bound(pSum, pSum+63, n)-pSum;
        ll diff=pSum[lwr]-(ll)n;
        vpii ret;
        for(int i=lwr;i>=0;--i){
            ll var=pSum[i]-pSum[i-1];
            if(i&1 && var<=diff) diff-=var;
            else ret.push_back(path[i]);
        }
        reverse(all(ret));
        for(pii& i : ret) cout<<i.first+1<<' '<<i.second+1<<'\n';
    }
}
