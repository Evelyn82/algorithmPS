#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXM=301;
int chez[MAXM], fried[MAXM];
int dp[MAXM][MAXM];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<n;++i) cin>>chez[i]>>fried[i];
    
    for(int i=0;i<n;++i){
        if(chez[i]>m||fried[i]>k) continue;
        for(int chz=m;chz>=chez[i];--chz){
            for(int fri=k;fri>=fried[i];--fri){
                dp[chz][fri]=max(dp[chz][fri], dp[chz-chez[i]][fri-fried[i]]+1);
            }
        }
    }cout<<dp[m][k]<<'\n';
}
