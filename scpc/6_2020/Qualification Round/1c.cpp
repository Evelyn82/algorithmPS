#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;
const int MXK=1e10;

int fw[MXK];
void add(int pos, int diff){
    while(pos<MXK){
        fw[pos]+=diff;
        pos+=(pos&-pos);
    }
}
int query(int pos){
    int cnt=0;
    while(pos){
        cnt+=fw[pos];
        pos&=(pos-1);
    }return cnt;
}
int sToi(string s){
    int n=0;
    int digit=1, sz=(int)s.size();
    for(int i=0;i<sz;++i){
        n+=(s[sz-i-1]*digit);
        digit*=10;
    }return n;
}
void solve(){
    memset(fw, 0, sizeof fw);
    int n,k,m; cin>>n>>k>>m;
    string s; cin>>s;
    
    // init
    for(int i=0;i<n-k;++i){
        int num=sToi(s.substr(i, k));
        add(num, 1);
    }
    for(int i)
    
    for(int i=0;i<n;++i){
        int diff=1-(int)(s[i]-'0');
        s[i]='1';
        
        // update
        if(diff!=0){
            
        }
        
        // range search
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        cout<<"Case #"<<tc<<'\n';
        solve();
    }
}
