#include <string>
#include <queue>
#include <memory.h>
#include <vector>
#define mp make_pair
using namespace std;
using pii=pair<int,int>;
using vpii=vector<pii>;

vector<vector<int>> adj;
vector<bool> vst;
vpii findFarthestNode(int n){
    for(int i=0;i<vst.size();++i) vst[i]=false;
    vst[n]=true;
    
    vpii ret;
    queue<pii> q;
    q.push(mp(n, 0));
    
    while(!q.empty()){
        pii now=q.front(); q.pop();
        
        for(int i=0;i<adj[now.first].size();++i){
            int nxt=adj[now.first][i];
            if(vst[nxt]) continue;
            vst[nxt]=true;
            int nxtCost=now.second+1;
          
            while(!ret.empty() && ret.back().second<nxtCost) ret.pop_back();
            ret.push_back(mp(nxt, nxtCost));
            q.push(mp(nxt, nxtCost));
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> edges) {
    adj.resize(n+1);
    vst.resize(n+1);
    for(vector<int> v : edges){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    vpii candidate1=findFarthestNode(1);
    
    vpii candidate2=findFarthestNode(candidate1[0].first);
    if(candidate2.size()>1) return candidate2[0].second;
    
    vpii candidate3=findFarthestNode(candidate2[0].first);
    if(candidate3.size()>1) return candidate3[0].second;
    return candidate3[0].second-1;
}
