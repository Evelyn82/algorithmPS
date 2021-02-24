#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll=long long;

struct Node{
    Node* child[26];
    int h, cnt, terminal;
    Node() : terminal(0), h(0), cnt(0){
        for(int i=0;i<26;++i) child[i]=nullptr;
    }
    ~Node(){
        for(int i=0;i<26;++i) if(child[i]) delete child[i];
    }
    
    void insert(const char* key, int depth){
        h=depth; cnt++;
        if(*key==0) {
            terminal++;
            return;
        }
        int next=(int)(*key-'A');
        if(child[next]==nullptr) child[next]=new Node();
        child[next]->insert(key+1, depth+1);
    }
    ll query(int k){
        if(this->cnt<k) return 0;
        
        ll ret=0; bool flag=false;
        for(int i=0;i<26;++i){
            if(child[i]==NULL) continue;
            if(child[i]->cnt>=k){
                ret=ret+(ll)child[i]->query(k);
                flag=true;
            }
        }
        
        ll ret1=(ll)(terminal/k)*h;
        //if(!flag) return ret1;
        return ret+ret1;
    }
};
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
        cout<<"Case #"<<tc<<": "<<root->query(k)<<'\n';
        delete root;
    }
}
