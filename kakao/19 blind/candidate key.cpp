#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

set<string> st[8];
map<string, int> mp[8];
set<int> superKey;
void getSuperKey(int idx, vector<int> ans, int key, const vector<vector<string>>& relation){
    if(idx==relation[0].size()) return;
    
    getSuperKey(idx+1, ans, key, relation);
    
    if(st[idx].size()==relation.size()) superKey.insert(1<<idx);
    else {
        set<int> s;
        for(int i=0;i<relation.size();++i){
            int num=mp[idx][relation[i][idx]];
            ans[i]=(ans[i] | (1<<num));
            s.insert(ans[i]);
        }
        if(s.size()==relation.size()) superKey.insert(key|(1<<idx));
        else getSuperKey(idx+1, ans, key|(1<<idx), relation);
    }
}
void getCandidateKey(){
    set<int>::iterator iter1, iter2;
    for(iter1=superKey.begin();iter1!=superKey.end();++iter1){
        iter2=superKey.end();
        for(--iter2;*iter1!=*iter2;--iter2){
            int num=*iter1 & *iter2;
            if(num==*iter1) superKey.erase(*iter2);
        }
    }
}
int solution(vector<vector<string>> relation) {
    for(int j=0;j<relation[0].size();++j){
        for(int i=0;i<relation.size();++i){
            string s=relation[i][j];
            st[j].insert(s);
            if(mp[j].find(s)==mp[j].end()) mp[j][s]=mp[j].size()+1;
        }
    }
    vector<int> ret(relation.size(), 0);
    getSuperKey(0, ret, 0, relation);
    getCandidateKey();
    return superKey.size();
}
