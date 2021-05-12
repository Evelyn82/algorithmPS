
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pil=pair<int, ll>;
using vpil=vector<pil>;
using vint=vector<int>;

vector<vpil> adj;
vector<bool> vst;
pair<vint, ll> findNode(int n){
    for(int i=0;i<vst.size();++i) vst[i]=false;
    vst[n]=true;
    
    long long leafDist=0;
    vint leaf;
    queue<pil> q;
    q.push(mp(n,0));
    while(!q.empty()){
        pil now=q.front(); q.pop();
        bool flag=false;
        for(int i=0;i<adj[now.first].size();++i){
            pil nxt=adj[now.first][i];
            if(vst[nxt.first]) continue;
            vst[nxt.first]=true;
            q.push(mp(nxt.first, now.second+nxt.second));
            flag=true;
        }
        
        if(!flag) {
            if(leafDist<=now.second){
                if(leafDist<now.second)leaf.clear();
                leaf.push_back(now.first);
                leafDist=now.second;
            }
        }
    }
    return mp(leaf, leafDist);
}
void del(int x, int y){
    vpil::iterator iter;
    for(iter=adj[x].begin();iter!=adj[x].end();++iter){
        if(iter->first==y) break;
    }adj[x].erase(iter);
    
    for(iter=adj[y].begin();iter!=adj[y].end();++iter){
        if(iter->first==x) break;
    }adj[y].erase(iter);
}
void connect(int x, pil y){
    adj[x].push_back(y);
    adj[y.first].push_back(mp(x, y.second));
}
ll solve(){
    pair<vint, ll> cand1=findNode(0);
    
    pair<vint, ll> cand2=findNode(cand1.first[0]);
    if(cand2.first.size()>1) return cand2.second;
    
    pair<vint, ll> cand3=findNode(cand2.first[0]);
    if(cand3.first.size()>1) return cand3.second;
    
    int del1=cand2.first[0], del2=cand3.first[0];
    pil opp1=adj[del1][0], opp2=adj[del2][0];
    
    del(del1, opp1.first);
    pair<vint, ll> cand4=findNode(del2);
    connect(del1, opp1);
    
    del(del2, opp2.first);
    pair<vint, ll> cand5=findNode(del1);
    return max(cand4.second, cand5.second);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin>>N;
    adj.resize(N);
    int a, b; ll c;
    for(int i=1;i<N;++i){
        cin>>a>>b>>c;
        adj[a-1].push_back(mp(b-1,c));
        adj[b-1].push_back(mp(a-1,c));
    }
    vst.resize(N, false);
    cout<<solve()<<'\n';
}
