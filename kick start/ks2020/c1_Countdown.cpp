#include <iostream>
#include <algorithm>
using namespace std;
const int MXN=2e5+2;

int arr[MXN], d[MXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        int n, k; cin>>n>>k;
        
        int prev, now; cin>>prev;
        int cnt=1, ans=0;
        for(int i=1;i<n;++i) {
            cin>>now;
            if(prev==now+1) cnt++;
            else cnt=1;
            
            if(now==1 && cnt>=k) ans++;
            prev=now;
        }
        
        cout<<"Case #"<<tc<<": "<<ans<<'\n';
    }
}
