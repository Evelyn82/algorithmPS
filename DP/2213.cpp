#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=1e5;

vector<int> adj[MX+1], ans;
int cost[MX+1], d[MX+1][2];
void dp(int now, int prev){
    d[now][1]=cost[now];
    for(int& nxt : adj[now]){
        if(nxt==prev) continue;
        dp(nxt, now);
        d[now][1]+=d[nxt][0];
        d[now][0]+=max(d[nxt][0], d[nxt][1]);
    }
}
void track(int now, int prev, bool include){
    if(include) ans.push_back(now);
    for(int& nxt : adj[now]){
        if(nxt==prev) continue;
        if(include) track(nxt, now, false);
        else track(nxt, now, d[nxt][0]<d[nxt][1]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    for(int i=1;i<=n;++i) cin>>cost[i];
    for(int i=0, u, v;i<n-1;++i){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp(1, 1);
    bool flag=d[1][1]>d[1][0];
    track(1, 1, flag);
    
    sort(ans.begin(), ans.end());
    cout<<d[1][flag]<<'\n';
    for(int& i : ans) cout<<i<<' ';
}
