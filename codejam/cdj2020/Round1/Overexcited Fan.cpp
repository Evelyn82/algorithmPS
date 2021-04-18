// MLE

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define mp make_pair
using namespace std;
using pii=pair<int,int>;

int dx[]={0,0,1,-1}, dy[]={-1,1,0,0};
int ctoi(char c){
    if(c=='W')return 0;
    if(c=='E')return 1;
    if(c=='S')return 2;
    return 3;
}
int manha(const pii& a, const pii& b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int solve(int x, int y, string& s){
    queue<pii> q, nxtq;
    q.push(mp(0,0));
    
    for(int idx=0;idx<s.size();++idx){
        int ci=ctoi(s[idx]);
        x+=dx[ci]; y+=dy[ci];
        vector<pii> tmp;
        while(!q.empty()){
            pii now = q.front(); q.pop();
            if(now.first==x && now.second==y) return idx+1;
           
            int mn=987654321;
            for(int i=0;i<4;++i){
                int nx=now.first+dx[i];
                int ny=now.second+dy[i];
                int dis=manha(mp(nx, ny),mp(x, y));
                if(mn>=dis){
                    if(mn>dis)tmp.clear();
                    if(nx==x && ny==y) return idx+1;
                    tmp.push_back(mp(nx, ny));
                    mn=dis;
                }
            }for(pii& i : tmp) nxtq.push(i);
            tmp.clear();
        }
        while(!nxtq.empty()) {q.push(nxtq.front()); nxtq.pop();}
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        int x, y; string s;
        cin>>x>>y>>s;
        cout<<"Case #"<<tc<<": ";
        int ans=solve(-y, x, s);
        if(ans==-1) cout<<"IMPOSSIBLE\n";
        else cout<<ans<<'\n';
    }
}
