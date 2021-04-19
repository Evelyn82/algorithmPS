#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

ll ans;
vector<vector<int>> adj;
vector<ll> cost;
vector<bool> vst;
ll solve(int n){
    vst[n]=true;
    for(int i=0;i<adj[n].size();++i){
        int nxt=adj[n][i];
        if(vst[nxt]) continue;
        ll cnt=solve(nxt);
        ans+=abs(cnt);
        cost[n]+=cnt;
    }return cost[n];
}
void makeTree(vector<vector<int>>& v){
    for(vector<int>& i : v){
        int u=i[0], v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    ll sum=0;
    cost.resize(a.size());
    for(int i=0;i<a.size();++i) {
        sum+=a[i];
        cost[i]=(ll)a[i];
    }
    if(sum!=0) return -1;
    
    adj.resize(a.size());
    makeTree(edges);
    
    ans=0;
    vst.resize(a.size(), false);
    solve(0);
    return ans;
}
