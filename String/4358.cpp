// 88ms

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ALPHA 128
int sz;
struct Node{
    vector<Node*> child;
    bool terminal;
    double cnt;
    Node() : terminal(false), cnt(0.0){
        child.resize(ALPHA, NULL);
    }
    ~Node(){
        for(int i=0;i<ALPHA;++i){
            if(child[i]) delete child[i];
        }
    }
    
    void insert(const char* key){
        if(*key==0) {
            terminal=true;
            cnt++;
            return;
        }
        int next=(int)*key;
        if(child[next]==NULL) child[next]=new Node();
        child[next]->insert(key+1);
    }
    
    void showRate(string s){
        if(terminal){
            cout<<s<<' '<<(cnt/sz)*100<<'\n';
        }
        for(int i=0;i<ALPHA;++i){
            if(child[i]!=NULL){
                child[i]->showRate(s+char(i));
            }
        }
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cout.precision(4);
    cout.setf(ios::fixed|ios::showpoint);
    //cout<<fixed;
    
    Node* node=new Node();
    string s;
    /*
     char input[32];
    while (!cin.getline(input, 31).eof()) {
    */
    while(getline(cin, s)){
        if(s.length()==0) break;
        node->insert(s.c_str());
        sz++;
    }
    node->showRate("");
}
