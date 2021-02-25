#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void dfs(int n, bool& flag, string& s, vector<bool>& vst, vector<bool>& act, const vector<vector<int>>& adj){
    vst[n]=true;
    act[n]=true;
    for(int nxt : adj[n]){
        if(act[nxt] && n^nxt) {flag=true; return;}
        if(!vst[nxt]) dfs(nxt, flag, s, vst, act, adj);
        if(flag) return;
    }
    act[n]=false;
    s+=(char)(n+'A');
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        int r, c; cin>>r>>c;
        vector<string> v(r);
        for(string& i : v) cin>>i;
        
        vector<vector<int>> adj(26);
        set<int> st;
        // init
        for(int j=0;j<c;++j){
            for(int i=1;i<r;++i){
                int from=v[i][j]-'A', to=v[i-1][j]-'A';
                st.insert(from); st.insert(to);
                if(from==to) continue;
                adj[from].push_back(to);
            }
        }
        
        vector<bool> vst(26, false);
        vector<bool> act(26, false);
        string ret=""; bool flag=false;
        set<int>::iterator it;
        for(it=st.begin();it!=st.end();++it) if(!vst[*it]) dfs(*it,flag, ret, vst, act, adj);
        reverse(ret.begin(), ret.end());
        
        cout<<"Case #"<<tc<<": ";
        if(flag || ret.size()!=st.size()) cout<<"-1\n";
        else cout<<ret<<"\n";
    }
}
