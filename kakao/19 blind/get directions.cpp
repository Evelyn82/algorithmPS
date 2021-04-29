#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define mp make_pair
using namespace std;
using pii=pair<int,int>;
const int MX=1e5;

struct Node{
    int idx, x, y;
    int low, high;
    
    Node* parent;
    Node* leftchild;
    Node* rightchild;
    Node(){}
    Node(int _idx, int _x, int _y) : idx(_idx), x(_x), y(_y){
        low=0; high=MX;
        leftchild=NULL;
        rightchild=NULL;
    }
    void setlow(){
        if(parent->rightchild==this) low=parent->x+1;
        else low=parent->low;
    }
    void sethigh(){
        if(parent->leftchild==this) high=parent->x-1;
        else high=parent->high;
    }
};

struct Pos{
    int n;
    vector<pair<int,int>> v; // ypos, idx
    Pos(){
        n=MX;
        v.resize(n*4, mp(-1,-1));
    }
    void insert(int node, int xpos, pair<int,int> d, int nodeleft, int noderight){
        if(nodeleft==noderight) {
            if(nodeleft==xpos) v[node]=d;
            return;
        }
        int mid=(nodeleft+noderight)/2;
        if(mid>=xpos) insert(node*2, xpos, d, nodeleft, mid);
        else insert(node*2+1, xpos, d, mid+1, noderight);
        
        if(v[node*2].first>v[node*2+1].first) v[node]=v[node*2];
        else v[node]=v[node*2+1];
    }
    void insert(int xpos, int ypos, int idx){
        insert(1, xpos, mp(ypos, idx), 0, n);
    }
    pii query(int left, int right, int node, int nodeleft, int noderight){
        if(left<=nodeleft && noderight<=right) return v[node];
        if(right<nodeleft || noderight<left) return mp(-1, -1);
        
        int mid=(nodeleft+noderight)/2;
        pii ret1=query(left, right, node*2, nodeleft, mid);
        pii ret2=query(left, right, node*2+1, mid+1, noderight);
        
        if(ret1.first>ret2.first) return ret1;
        return ret2;
    }
    int query(int left, int right){
        pii ret=query(left, right, 1, 0, n);
        return ret.second;
    }
};

vector<Node*> node;
Pos* xpos;
void makeTree(int idx, bool root){
    if(!root){
        node[idx]->setlow();
        node[idx]->sethigh();
    }
    int left=xpos->query(node[idx]->low, node[idx]->x-1);
    if(left!=-1){
        node[idx]->leftchild=node[left];
        node[left]->parent=node[idx];
    }
    
    int right=xpos->query(node[idx]->x+1,node[idx]->high);
    if(right!=-1){
        node[idx]->rightchild=node[right];
        node[right]->parent=node[idx];
    }
    
    if(left!=-1) makeTree(left, false);
    if(right!=-1)makeTree(right, false);
}
void solve(int root){
    node[root]->low=0;
    node[root]->high=MX;
    
    makeTree(root, true);
}
void preorder(vector<int>& ret, int idx){
    ret.push_back(node[idx]->idx+1);
    
    if(node[idx]->leftchild) preorder(ret, node[idx]->leftchild->idx);
    if(node[idx]->rightchild) preorder(ret, node[idx]->rightchild->idx);
}
void postorder(vector<int>& ret, int idx){
    if(node[idx]->leftchild) postorder(ret, node[idx]->leftchild->idx);
    if(node[idx]->rightchild) postorder(ret, node[idx]->rightchild->idx);

    ret.push_back(node[idx]->idx+1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int sz=(int)nodeinfo.size();
    node.resize(sz);
    xpos=new Pos();
    for(int i=0;i<sz;++i){
        node[i]=new Node(i,nodeinfo[i][0], nodeinfo[i][1]);
        xpos->insert(nodeinfo[i][0], nodeinfo[i][1], i);
    }

    int root=xpos->query(0, MX);
    solve(root);
    
    vector<vector<int>> answer;
    vector<int> pre; preorder(pre,root);
    vector<int> post; postorder(post, root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
