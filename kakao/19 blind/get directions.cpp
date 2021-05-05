#include <string>
#include <vector>
#define mp make_pair
using namespace std;
using pii=pair<int,int>;
const int MX=1e5+1;
struct Node{
    int idx, x, y;
    int low, high; // range
    bool isRoot;
    
    Node* leftchild;
    Node* rightchild;
    
    Node(){}
    Node(int _idx, int _x, int _y):idx(_idx), x(_x), y(_y), low(0), high(1e5), isRoot(false){
        leftchild=rightchild=NULL;
    }
    void insert(Node* newNode){
        if(x<newNode->x){ //set rightchild
            if(rightchild) rightchild->insert(newNode);
            else {
                rightchild=newNode;
                newNode->low=x+1;
                newNode->high=high;
            }
        }
        else {  // set leftchild
            if(leftchild) leftchild->insert(newNode);
            else {
                leftchild=newNode;
                
                newNode->low=low;
                newNode->high=x-1;
            }
        }
    }
    
};
vector<pii> h[MX];
vector<Node*> tree;

void preorder(Node* node, vector<int>& ret){
    ret.push_back(node->idx+1);
    if(node->leftchild) preorder(node->leftchild, ret);
    if(node->rightchild) preorder(node->rightchild, ret);
}
void postorder(Node* node, vector<int>& ret){
    if(node->leftchild) postorder(node->leftchild, ret);
    if(node->rightchild) postorder(node->rightchild, ret);
    ret.push_back(node->idx+1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    tree.resize(nodeinfo.size());
    int isRoot, rootH=-1;
    for(int i=0;i<nodeinfo.size();++i){
        int x=nodeinfo[i][0], y=nodeinfo[i][1];
        tree[i]=new Node(i, x, y);
        h[y].push_back(mp(x, i));
        if(rootH<y) {
            rootH=y; isRoot=i;
        }
    }
    tree[isRoot]->isRoot=true;
    for(int i=rootH-1;i>=0;--i){
        for(int j=0;j<h[i].size();++j){
            tree[isRoot]->insert(tree[h[i][j].second]);
        }
    }
    vector<int> pre, post;
    preorder(tree[isRoot], pre);
    postorder(tree[isRoot], post);
    
    vector<vector<int>> answer;
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
