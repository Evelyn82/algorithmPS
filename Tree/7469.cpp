#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=1e5;

vector<int> v[MX*4];
void insert(int low, int high, int node, int idx, int cost){
    if(idx<low || high<idx) return;
    v[node].push_back(cost);
    int mid=low+high>>1;
    if(low^high){
        insert(low, mid, node*2, idx, cost);
        insert(mid+1, high, node*2+1, idx, cost);
    }
}
int query(int low, int high, int node, int nodeleft, int noderight, int cost){
    if(high<nodeleft || noderight<low) return 0;
    if(low<=nodeleft && noderight<=high) return upper_bound(v[node].begin(), v[node].end(), cost)-v[node].begin();
    int mid=nodeleft+noderight>>1;
    return query(low, high, node*2, nodeleft, mid, cost)+query(low, high, node*2+1, mid+1, noderight, cost);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        int num; cin>>num;
        insert(1, n, 1, i, num);
    }
    for(int i=0;i<MX*4;++i) sort(v[i].begin(), v[i].end());
    for(int i=0;i<m;++i){
        int a,b,kth; cin>>a>>b>>kth;
        int low=-1e9, high=1e9;
        
        while(low<=high){
            int mid=low+high>>1;
        
            if(query(a, b, 1, 1, n, mid)<kth) low=mid+1;
            else high=mid-1;
        }
        cout<<low<<'\n';
    }
}
