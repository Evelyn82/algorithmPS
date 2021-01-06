#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Cafe{
    int n;
    vector<ll> rsq;
    
    Cafe(vector<ll>&v){
        n=v.size();
        rsq.resize(n*4,0);
        init(0, n-1, 1, v);
    }
    ll init(int left, int right, int node, vector<ll>& v){
        if(left==right) return rsq[node]=v[left];
        
        int mid=(left+right)/2;
        return rsq[node]=init(left, mid, node*2, v)+init(mid+1, right, node*2+1, v);
    }
    ll query(int nodeleft, int noderight, int node, int left, int right){
        if(right<nodeleft||noderight<left) return 0;
        if(left<=nodeleft&&noderight<=right) return rsq[node];
        
        int mid=(nodeleft+noderight)/2;
        return query(nodeleft, mid, node*2, left, right)+query(mid+1, noderight, node*2+1, left, right);
    }
    void query(int left, int right){
        if(left>right) swap(left, right);
        cout<<query(0, n-1, 1, left-1, right-1)<<'\n';
    }
    ll update(int nodeleft, int noderight, int node, int idx, ll num){
        if(idx<nodeleft||noderight<idx) return rsq[node];
        if(nodeleft==noderight) return rsq[node]=num;
        
        int mid=(nodeleft+noderight)/2;
        return rsq[node]=update(nodeleft, mid, node*2, idx, num)+update(mid+1, noderight ,node*2+1, idx, num);
    }
    void update(int idx, ll num){
        update(0, n-1, 1, idx-1, num);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,q; cin>>n>>q;
    vector<ll> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    Cafe* node=new Cafe(v);
    
    int a,b,c; ll d;
    for(int i=0;i<q;++i){
        cin>>a>>b>>c>>d;
        node->query(a, b);
        node->update(c, d);
    }
}
