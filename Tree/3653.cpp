#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> fw, pos;
void insert(int idx, int diff){
    while(idx<=fw.size()){
        fw[idx]+=diff;
        idx+=(idx & -idx);
    }
}
int query(int idx){
    int cnt=0;
    while(idx){
        cnt+=fw[idx];
        idx-=(idx& -idx);
    }return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        fw.clear(); fw.resize(n+m,0);
        pos.clear(); pos.resize(n+1);
        
        for(int i=1;i<=n;++i) {
            pos[i]=m+i;
            insert(pos[i], 1);
        }
        int now=m;
        for(int i=0;i<m;++i){
            int num; cin>>num;
            cout<<query(pos[num])-1<<' ';
            insert(pos[num],-1);
            pos[num]=now--;
            insert(pos[num],1);
        }cout<<'\n';
    }
}
