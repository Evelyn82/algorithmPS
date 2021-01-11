//
//  7578.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/12.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN=5e5+1;
const int MAXM=1e6+1;
int n, a[MAXN], b[MAXM];
vector<int> rcq; // range count query

void update(int idx, int node, int nodeleft, int noderight){
    if(nodeleft==noderight){
        rcq[node]=1;
        return;
    }
    int mid=(nodeleft+noderight)/2;
    if(idx<=mid) update(idx, node*2, nodeleft, mid);
    else update(idx, node*2+1, mid+1, noderight);
    rcq[node]=rcq[node*2]+rcq[node*2+1];
}
int cntQuery(int left, int right, int node, int nodeleft, int noderight){
    if(right<nodeleft || noderight<left) return  0;
    if(left<=nodeleft && noderight<=right) return rcq[node];
    
    int mid=(nodeleft+noderight)/2;
    return cntQuery(left, right, node*2, nodeleft, mid) + cntQuery(left, right, node*2+1, mid+1, noderight);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    int j;
    for(int i=0;i<n;++i){
        cin>>j;
        b[j]=i;
    }
    int sz=(int)(ceil(log2(n))+1e-9);
    int ssz=(1<<(sz+1));
    rcq.resize(ssz, 0);
    
    ll ret=0;
    for(int i=0;i<n;++i){
        ret+=cntQuery(b[a[i]], n-1, 1, 0, n-1);
        update(b[a[i]], 1, 0, n-1);
    }cout<<ret<<'\n';
}
