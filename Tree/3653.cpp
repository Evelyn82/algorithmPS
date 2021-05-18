/*
n+m 크기의 fenwick tree로 가지고 있는 영화 n개를 idx m+1 부터 차례로 추가한 한 뒤, 보려는 영화 index 범위까지 탐색
보려는 영화는 맨 앞에 오도록 현재 맨 앞 index - 1 로 계속 update
*/

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
