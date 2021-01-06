#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Node{
    int n;
    vector<int> rmq;
    Node(const vector<int>& v){
        n=v.size();
        rmq.resize(n*4,0);
        init(0, n-1, 1, v);
    }
    int init(int left, int right, int node, const vector<int>& v){
        if(left==right) return rmq[node]=v[left];
        
        int mid=(left+right)/2;
        int l=init(left, mid, node*2, v);
        int r=init(mid+1, right, node*2+1, v);
        return rmq[node]=min(l,r);
    }
    int update(int nodeleft, int noderight, int node, int idx, int num){
        if(idx<nodeleft||noderight<idx) return rmq[node];
        if(nodeleft==noderight) return rmq[node]=num;
        
        int mid=(nodeleft+noderight)/2;
        int l=update(nodeleft, mid, node*2 ,idx, num);
        int r=update(mid+1, noderight, node*2+1, idx, num);
        return rmq[node]=min(l,r);
    }
    void update(int idx, int num){
        update(0, n-1, 1,idx-1, num);
    }
    int query(int nodeleft, int noderight, int node, int left, int right){
        if(right<nodeleft||noderight<left) return 1e9;
        if(left<=nodeleft&&noderight<=right) return rmq[node];
        
        int mid=(nodeleft+noderight)/2;
        int l=query(nodeleft, mid, node*2, left, right);
        int r=query(mid+1, noderight, node*2+1, left, right);
        return min(l, r);
    }
    void query(int left, int right){
        cout<<query(0, n-1, 1, left-1, right-1)<<'\n';
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<int> v(n);
    for(int& i : v) cin>>i;
    
    Node* node=new Node(v);
    int m; cin>>m;
    int a, b, c;
    while(m--){
        cin>>a>>b>>c;
        if(a==1) node->update(b, c);
        else node->query(b, c);
    } 
}
