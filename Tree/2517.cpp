// 좌표압축 후 fenwick tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int, int>;

vector<int> fw;
int query(int idx){
    int cnt=0;
    while(idx){
        cnt+=fw[idx];
        idx-=(idx & -idx);
    }return cnt;
}
void add(int idx){
    while(idx<fw.size()){
        fw[idx]++;
        idx+=(idx& -idx);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N; cin>>N;
    vector<pii> v(N);
    for(int i=0;i<N;++i){
        cin>>v[i].second;
        v[i].first=i;
    }
    sort(v.begin(), v.end(), [&](const pii& a, const pii& b){
        return a.second<b.second;
    });
    
    for(int i=1;i<=N;++i) v[i-1].second=i;
    sort(v.begin(), v.end(), [&](const pii& a, const pii& b){
        return a.first<b.first;
    });
    
    fw.resize(N+1,0);
    int cnt=0;
    for(pii& p : v){
        cout<<cnt-query(p.second)+1<<'\n';
        add(p.second);
        cnt++;
    }
}
