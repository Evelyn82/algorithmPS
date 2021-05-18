#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
const int MX=1e5;

struct fw{
    int low, high, cost;
    int idx;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i].second;
        v[i].first=i+1;
    }
    sort(v.begin(), v.end(), [&](const pii& a, const pii& b){
        return a.second>b.second;
    });
    
    int m; cin>>m;
    vector<fw> query(m);
    for(int i=0;i<m;++i){
        cin>>query[i].low>>query[i].high>>query[i].cost;
        query[i].idx=i;
        query[i].low--;
    }
    sort(query.begin(), query.end(), [&](const fw& a, const fw& b){
        return a.cost>b.cost;
    });
    
    vector<int> cnt(MX+1);
    auto update=[&](int i){
        while(i<=n){
            cnt[i]++;
            i+=(i & -i);
        }
    };
    
    auto count=[&](int i){
        int ret=0;
        while(i){
            ret+=cnt[i];
            i-=(i & -i);
        }return ret;
    };

    vector<int> answer(m);
    for(int i=0, j=0;i<m;++i){
        while(v[j].second>query[i].cost) update(v[j++].first);
        answer[query[i].idx]=count(query[i].high)-count(query[i].low);
    }
    
    for(int i=0;i<m;++i) cout<<answer[i]<<'\n';
}
