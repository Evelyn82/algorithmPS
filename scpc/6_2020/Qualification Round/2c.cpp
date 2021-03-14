#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MXK=2e7+2;
const int MXN=2e5+1;

ll pay[MXN];
ll cum[MXN]; // cumulative
int fw[MXK];
void add(ll pos, ll diff){
    while(pos<MXK){
        fw[pos]+=diff;
        pos+=(pos&-pos);
    }
}
int sum(ll pos){
    int cnt=0;
    while(pos>0){
        cnt+=fw[pos];
        pos &= (pos-1);
    }return cnt;
}
int kth(int pos){
    int low=1, high=MXK;
    while(low<high){
        int mid=(low+high)/2;
        if(pos<=sum(mid)) high=mid;
        else low=mid+1;
    }return low;
}
void solve(){
    int n,K,Q; cin>>n>>K>>Q;
    vector<ll> prefixSum;
    
    for(int i=1;i<=n;++i){
        cin>>pay[i];
        cum[i]=pay[i]+cum[i-1];
        if(K<=i){
            add(cum[i]-cum[i-K], 1);
            prefixSum.push_back(cum[i]-cum[i-K]);
        }
    }
    int mid=(n-K+3)/2;
    cout<<kth(mid)<<' ';
    
    int x, y;
    for(int i=0;i<Q;++i){
        cin>>x>>y;
        ll diff=y-pay[x];
        pay[x]=y;
        
        if(diff){
            for(int j=max(0, x-K);j<min(x, n-K+1);++j){
                add(prefixSum[j], -1);
                add(prefixSum[j]+diff, 1);
                prefixSum[j]+=diff;
            }
        }
        cout<<kth(mid)<<' ';
    }cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        cout<<"Case #"<<tc<<'\n';
        
        memset(pay, 0, sizeof pay);
        memset(fw, 0, sizeof fw);
        solve();
    }
}
