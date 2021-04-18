#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n,c;
int ret[101];
bool solve(){
    if(c<n-1 || c>=(n*(n+1))/2) return false;
    if(n-1==c) {
        for(int i=1;i<=n;++i) ret[i]=i;
        return true;
    }
    
    stack<int> st;
    int tmpc=c-(n-1), rev;
    for(int i=1;i<n;++i){
        rev=min(n-i+1, tmpc+1);
        st.push(rev);
        tmpc-=rev-1;
    }
    
    for(int i=0;i<=n;++i) ret[i]=i;
    for(int i=n-1;i>0;--i){
        reverse(ret+i, ret+i+st.top());
        st.pop();
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        cin>>n>>c;
        cout<<"Case #"<<tc<<": ";
        if(solve()) for(int i=1;i<=n;++i) cout<<ret[i]<<' ';
        else cout<<"IMPOSSIBLE";
        cout<<"\n";
    }
}
