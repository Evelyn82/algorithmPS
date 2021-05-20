#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
const int MX=2e5;
const int DIV=1000000007;

ll fw[MX+2];
ll cnt[MX+2];
void update(ll v[], int idx, int cost){
    while(idx<=MX){
        v[idx]+=cost;
        idx+=(idx & -idx);
    }
}
ll sum(ll v[], int idx){
    ll answer=0;
    while(idx){
        answer+=v[idx];
        idx-=(idx& -idx);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    int num; cin>>num;
    num++;
    update(fw, num, num);
    update(cnt, num, 1);
    
    ll answer=1;
    for(int i=2;i<=n;++i){
        cin>>num; num++;
        
        update(fw, num, num);
        update(cnt, num, 1);
        ll diff;
        ll lower=sum(fw, num);
        ll lowerc=sum(cnt, num);
        diff=((num*lowerc)-lower)%DIV;
        
        ll upper=sum(fw, MX)-lower;
        ll upperc=sum(cnt, MX)-lowerc;
        diff+=(upper-num*upperc)%DIV;
        
        answer=(answer*diff) % DIV;
    }cout<<answer%DIV<<'\n';
}
