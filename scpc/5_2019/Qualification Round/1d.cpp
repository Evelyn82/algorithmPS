// kdh9949
// 0.06158ms 

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>
#include <numeric>
using namespace std;

using ll=long long;
using ld=long double;
using pii=pair<int,int>;
using pil=pair<int, ll>;
using pli=pair<ll, int>;
using pll=pair<ll, ll>;

using vint=vector<int>;
using vll=vector<ll>;
using vld=vector<ld>;
using vpii=vector<pii>;
using vpil=vector<pil>;
using vpli=vector<pli>;
using vpll=vector<pll>;

#define all(v) v.begin(), v.end()
void solve(){
    int n; cin>>n;
    vld r(n);
    for(ld& i : r) cin>>i;
    
    vint kth(n);
    iota(all(kth), 0);
    sort(all(kth), [&](int x, int y){return r[x]<r[y];});
    
    auto put=[&](vint &p, bool print){
        vld pos(n);
        ld mn=-r[p[0]], mx=r[p[0]];
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                pos[i]=max(pos[i], pos[j]+2*sqrt(r[p[i]]*r[p[j]]));
            }
            mx=max(mx, pos[i]+r[p[i]]);
            mn=min(mn, pos[i]-r[p[i]]);
        }
        
        if(print){
            vint q(n);
            for(int i=0;i<n;++i) q[p[i]]=i;
            for(int i=0;i<n;++i) cout<<pos[q[i]]<<'\n';
        }return mx-mn;
    };
    
    vint p(n);
    int c=0;
    for(int i=0;i<n;i+=2) p[i]=kth[c++];
    for(int i=n-1-(n&1);i>=0;i-=2) p[i]=kth[c++];
    ld mn=put(p, false);
    
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> rnd(0, n-1);
    
    int trial=100;
    while(trial--){
        int x, y;
        do{
            x=rnd(mt);
            y=rnd(mt);
        }while(x==y);
        swap(p[x], p[y]);
        ld cur=put(p, false);
        if(mn>cur) mn=cur;
        else swap(p[x], p[y]);
    }
    put(p, true);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed;
    cout.precision(12);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        cout<<"Case #"<<tc<<'\n';
        solve();
    }
}
