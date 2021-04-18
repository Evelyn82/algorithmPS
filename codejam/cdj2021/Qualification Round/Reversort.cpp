#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MXN=101;
int n;
int arr[MXN], idx[MXN];
int chg(int low, int high){
    int d=high;
    for(int i=low;i<=high;++i){
        idx[arr[i]]=d--;
    }
    reverse(arr+low, arr+high+1);
    
    return high-low+1;
}
void solve(){
    int ans=0;
    for(int i=1;i<n;++i){
        int j=idx[i];
        ans+=chg(i, j);
    }cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        cin>>n;
        for(int i=1;i<=n;++i) {
            cin>>arr[i];
            idx[arr[i]]=i;
        }
        cout<<"Case #"<<tc<<": ";
        solve();
    }
}
