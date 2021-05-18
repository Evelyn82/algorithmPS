#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=1e5;

vector<int> v[MX*4];
void insert(int low, int high, int node, int idx, int cost){
    if(idx<low || high<idx) return;
    v[node].push_back(cost);
    if(low^high){
        int mid = low+high>>1;
        insert(low, mid, node*2, idx, cost);
        insert(mid+1, high, node*2+1, idx, cost);
    }
}
int query(int low, int high, int node, int nodeleft, int noderight, int kth){
    if(high<nodeleft || noderight<low) return 0;
    if(low<=nodeleft && noderight<=high) return v[node].end()-upper_bound(v[node].begin(), v[node].end(), kth);
    int mid=nodeleft+noderight>>1;
    return query(low, high, node*2, nodeleft, mid, kth)+query(low, high, node*2+1, mid+1, noderight, kth);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        int m; cin>>m;
        insert(1, n, 1, i, m);
    }
    for(int i=0;i<MX*4;++i) sort(v[i].begin(), v[i].end());
    int m, a, b, c; cin>>m;
    int answer=0;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        a^=answer;
        b^=answer;
        c^=answer;
        answer=query(a, b, 1, 1, n, c);
        cout<<answer<<'\n';
    }
}
