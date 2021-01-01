#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN=1e5+1;
pair<int,int> arr[MAXN];
bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.first>b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll sum=0;
        for(int i=1;i<=n;++i) {
            cin>>arr[i].first;
            sum+=arr[i].first;
            arr[i].second=0;
        }
        int u,v;
        for(int i=0;i<n-1;++i){
            cin>>u>>v;
            arr[u].second++;
            arr[v].second++;
        }
        sort(arr+1, arr+1+n, cmp);
        
        cout<<sum<<' ';
        for(int i=1;i<=n;++i){
            for(int j=arr[i].second;j>1;--j){
                sum+=arr[i].first;
                cout<<sum<<' ';
            }
        }cout<<'\n';
    }
}
