#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

int memory[101], cost[101];
int d[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m; cin>>n>>m;
    
    for(int i=0;i<n;++i) cin>>memory[i];
    int cs=0; // costSum
    for(int i=0;i<n;++i){
        cin>>cost[i];
        cs+=cost[i];
    }
    
    for(int i=0;i<n;++i){
        for(int j=cs;j>=cost[i];--j){
            d[j]=max(d[j], d[j-cost[i]]+memory[i]);
        }
    }
    
    int i;
    for(i=0;i<=cs,d[i]<m;++i);
    cout<<i<<'\n';
}
