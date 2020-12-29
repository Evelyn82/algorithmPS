#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int sum=0, ret1=0,j;
        int n; cin>>n;
        for(int i=0;i<n;++i){
            cin>>j;
            sum+=j;
            if(sum>0){
                ret1+=sum;
                sum=0;
            }
        }
        
        sum=0;
        int ret2=0;
        int m; cin>>m;
        for(int i=0;i<m;++i){
            cin>>j;
            sum+=j;
            if(sum>0){
                ret2+=sum;
                sum=0;
            }
        }
        cout<<ret1+ret2<<'\n';
    }
}
