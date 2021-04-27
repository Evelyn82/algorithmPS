#include <string>
#include <vector>

using namespace std;
const int MX=27;
int chgInt(char c){
    return (c=='?'?26:c-97);
}
struct Trie{
    bool terminal;
    int cnt;
    Trie* child[27];
    
    Trie() : terminal(false), cnt(0) {
        for(int i=0;i<27;++i) child[i]=NULL;
    }
    void insert(const char* key){
        if(*key==0){
            terminal=true;
            return;
        }
        int nxt=chgInt(*key);
        if(!child[nxt]) child[nxt]=new Trie();
        child[nxt]->insert(key+1);
    }
    void query(const char* key){
        if(*key==0){
            if(terminal==true) cnt++;
            return;
        }
        
        int nxt=chgInt(*key);
        if(child[26]) child[26]->query(key+1);
        if(!child[nxt]) return;
        child[nxt]->query(key+1);
    }
    
    int getCnt(const char* key){
        if(*key==0) return cnt;
        
        int nxt=chgInt(*key);
        return child[nxt]->getCnt(key+1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    Trie* root=new Trie();
    for(string& s : queries){
        root->insert(s.c_str());
    }
    for(string& s : words){
        root->query(s.c_str());
    }
    
    vector<int> answer;
    for(string& s : queries){
        answer.push_back(root->getCnt(s.c_str()));
    }
    return answer;
}
