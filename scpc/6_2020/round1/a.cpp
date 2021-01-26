#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 1;
ll arr1[MAXN], arr2[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        int n,k; cin>>n>>k;
        for(int i = 0; i < n; ++i) cin>>arr1[i];
        for(int i = 0; i < n; ++i) cin>>arr2[i];
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        
        cout<<"Case #"<<tc<<'\n';
   
        //cout<<max(arr1[0] + arr2[k - 1], arr1[k - 1] + arr2[0])<<'\n'; ->WA
        
        ll ret = 0;
        for(int i = 0; i < k; ++i){
            ret = max(ret, arr1[i] + arr2[k - i - 1]);
        }cout << ret << '\n';
    }
}
