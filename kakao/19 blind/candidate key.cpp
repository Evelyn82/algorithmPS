#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

set<string> st[8];
map<string, int> mp[8];
vector<int> superKey[8];
void getSuperKey(int idx, vector<int> ans, int key, const vector<vector<string>>& relation){
    if(idx==relation[0].size()) return;
    
    getSuperKey(idx+1, ans, key, relation);
    
    if(st[idx].size()==relation.size()) superKey[idx].push_back(1<<idx);
    else {
        set<int> s;
        for(int i=0;i<relation.size();++i){
            int num=mp[idx][relation[i][idx]];
            ans[i]=(ans[i] | (1<<num));
            s.insert(ans[i]);
        }
        if(s.size()==relation.size()) superKey[idx].push_back(key|(1<<idx));
        else getSuperKey(idx+1, ans, key|(1<<idx), relation);
    }
}
int getCandidateKey(int sz){
    set<int> candidateKey;
    for(int c=0;c<sz;++c){
        if(!superKey[c].size()) continue;
        if(superKey[c].size()==1) candidateKey.insert(superKey[c][0]);
        else{
            sort(superKey[c].begin(), superKey[c].end());
            for(int i=0;i<superKey[c].size();++i){
                for(int j=i+1;j<superKey[c].size();++j){
                    int ret=0, a=superKey[c][i], b=superKey[c][j];
                    for(int k=0;k<8;++k){
                        if((a&(1<<k)) && (b&(1<<k))) ret=ret|(1<<k);
                    }candidateKey.insert(ret);
                }
            }
        }
    }return candidateKey.size();
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
    return getCandidateKey(relation[0].size());
}
