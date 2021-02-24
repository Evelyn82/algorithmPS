#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll=long long;

struct Node{
    Node* child[26];
    int h, cnt, terminal;
    Node() : h(0), cnt(0), terminal(0){
        for(int i=0;i<26;++i) child[i]=NULL;
    }
    ~Node(){
        for(int i=0;i<26;++i) if(child[i]) delete child[i];
    }
    
    void insert(const char* key, int depth){
        this->h=depth; this->cnt++;
        if(*key==0) {
            terminal++;
            return;
        }
        int next=(int)(*key-'A');
        if(child[next]==NULL) child[next]=new Node();
        child[next]->insert(key+1, depth+1);
    }
    
};
int query(int k, Node* root, int& ans){
    int rem=root->terminal;
    for(int i=0;i<26;++i){
        Node* next=root->child[i];
        if(next==NULL) continue;
        rem+=query(k, next, ans);
    }
    ans+=(rem/k)*root->h;
    return rem%k;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        Node* root=new Node();
        int n, k; cin>>n>>k;
        for(int i=0;i<n;++i){
            string s; cin>>s;
            root->insert(s.c_str(), 0);
        }
        
        int ans=0;
        query(k, root, ans);
        cout<<"Case #"<<tc<<": "<<ans<<'\n';
        delete root;
    }
}
