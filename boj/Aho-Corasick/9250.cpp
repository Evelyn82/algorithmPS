#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Trie{
    Trie* go[26];
    Trie* fail;
    bool output;
    
    Trie(){
        fill(go, go+26, nullptr);
        output=false;
    }
    ~Trie(){
        for(int i=0;i<26;++i){
            if(go[i]) delete go[i];
        }
    }
    void insert(const char* key){
        if(*key==0){
            output=true;
            return;
        }
        int next=*key-'a';
        if(go[next]==nullptr) go[next]=new Trie();
        go[next]->insert(key+1);
    }
};
int main(){
    int n; char str[10001];
    Trie* root=new Trie();
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%s", str);
        root->insert(str);
    }
    
    queue<Trie*> q;
    root->fail=root;
    q.push(root);
    while(!q.empty()){
        Trie* now=q.front(); q.pop();
        
        for(int i=0;i<26;++i){
            Trie* next=now->go[i];
            if(!next) continue;
            
            if(now==root) next->fail=root;
            else{
                Trie *ancestor=now->fail;
                while(ancestor!=root && !ancestor->go[i]) ancestor=ancestor->fail;
                if(ancestor->go[i]) ancestor=ancestor->go[i];
                next->fail=ancestor;
            }
            
            if(next->fail->output) next->output=true;
            q.push(next);
        }
    }
    
    int m; scanf("%d", &m);
    for(int i=0;i<m;++i){
        scanf("%s", str);
        
        Trie* now=root;
        bool result=false;
        for(int c=0;str[c];++c){
            int next=str[c]-'a';
            while(now!=root && !now->go[next]) now=now->fail;
            if(now->go[next]) now=now->go[next];
            if(now->output){
                result=true;
                break;
            }
        }
        puts(result? "YES":"NO");
    }
    delete root;
}
