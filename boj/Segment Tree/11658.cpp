//
//  11658.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int n;
    vector<int> rsq;
    vector<int> lazy;
    Node(const vector<int>& v){
        n=v.size();
        rsq.resize(n*4,0);
        lazy.resize(n*4,0);
        init(0, n-1, 1, v);
    }
    int init(int left, int right, int node, const vector<int>&v){
        if(left==right) return rsq[node]=v[left];
        
        int mid=(left+right)/2;
        return rsq[node]=init(left, mid, node*2, v)+init(mid+1, right, node*2+1, v);
    }
    void updateLazy(int left, int right, int node){
        if(lazy[node]!=0){
            rsq[node]+=lazy[node]*(right-left+1);
            if(left!=right){
                lazy[node*2]+=lazy[node];
                lazy[node*2+1]+=lazy[node];
            }lazy[node]=0;
        }
    }
    void update(int idx, int num, int node, int nodeleft, int noderight){
        updateLazy(nodeleft, noderight, node);
        if(nodeleft==noderight){
            if(nodeleft==idx){
                lazy[node]-=rsq[node];
                rsq[node]=num;
            }return;
        }
        int mid=(nodeleft+noderight)/2;
        if(idx<=mid) update(idx, num, node*2, nodeleft, mid);
        else update(idx, num, node*2+1, mid+1, noderight);
    }
    void update(int idx, int num){
        update(idx-1, num, 1, 0, n-1);
    }
    int query(int left, int right, int node, int nodeleft, int noderight){
        updateLazy(nodeleft, noderight, node);
        if(right<nodeleft||noderight<left) return 0;
        if(left<=nodeleft&&noderight<=right) return rsq[node];
        
        int mid=(nodeleft+noderight)/2;
        return query(left, right, node*2, nodeleft, mid)+query(left, right, node*2+1, mid+1, noderight);
    }
    void query(int left, int right){
        cout<<query(left-1, right-1, 1, 0, n-1);
    }
};
vector<Node*> node;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<int> v(n);
    
    node.resize(n);
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) cin>>v[i];
        node[i]=new Node(v);
    }
    int w,a,b,c,d;
    for(int i=0;i<m;++i){
        cin>>w;
        if(w){
            cin>>a>>b>>c;
            node[a-1]->update(b, c);
        }
        else{
            cin>>a>>b>>c>>d;
            if(a>c) swap(a,c);
            for(int j=a-1;j<c;++j){
                node[j]->query(b, d);
            }
        }
    }
}
