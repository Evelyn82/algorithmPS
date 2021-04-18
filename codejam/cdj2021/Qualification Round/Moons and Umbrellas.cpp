#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;
const int MXN=1001;

int x, y;
int d[MXN][2];
string s;
void solve(){
    memset(d, 0, sizeof d);
    int sz=s.size();
    for(int i=1;i<sz;++i){
        if(s[i]=='C'){
            int cost;
            if(s[i-1]=='C')  cost=d[i-1][0];
            else if(s[i-1]=='J') cost=d[i-1][1]+y;
            else cost=min(d[i-1][0], d[i-1][1]+y);
            d[i][0]=d[i][1]=cost;
        }
        else if(s[i]=='J'){
            int cost;
            if(s[i-1]=='C') cost=d[i-1][0]+x;
            else if(s[i-1]=='J') cost=d[i-1][1];
            else cost=min(d[i-1][0]+x, d[i-1][1]);
            d[i][0]=d[i][1]=cost;
        }
        else{
            if(s[i-1]=='C') {
                d[i][0]=d[i-1][0];
                d[i][1]=d[i-1][0]+x;
            }
            else if(s[i-1]=='J'){
                 d[i][0]=d[i-1][1]+y;
                d[i][1]=d[i-1][1];
            }
            else{
                d[i][0]=min(d[i-1][0], d[i-1][1]+y);
                d[i][1]=min(d[i-1][0]+x, d[i-1][1]);
            }
        }
    }cout<<min(d[sz-1][0], d[sz-1][1])<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        cin>>x>>y;
        cin>>s;
        cout<<"Case #"<<tc<<": ";
        solve();
    }
}
