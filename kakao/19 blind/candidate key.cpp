#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> candidateKey;
set<string> uniqueCnt;
void getSuperKey(int idx, int key, vector<string> ans, const vector<vector<string>>& relation){
    if(idx==relation[0].size()) return;
    
    getSuperKey(idx+1, key, ans, relation);
    
    uniqueCnt.clear();
    for(int i=0;i<relation.size();++i){
        ans[i]+=relation[i][idx];
        uniqueCnt.insert(ans[i]);
    }
    if(uniqueCnt.size()==relation.size()) candidateKey.push_back(key|(1<<idx));
    else getSuperKey(idx+1, key|(1<<idx), ans, relation);
    
}
void getCandidatekey(){
    sort(candidateKey.begin(), candidateKey.end());
    for(int i=0;i<candidateKey.size();++i){
        for(int j=(int)candidateKey.size()-1;j>i;--j){
            int num=candidateKey[i] & candidateKey[j];
            if(num==candidateKey[i]) candidateKey.erase(candidateKey.begin()+j);
        }
    }
}
int solution(vector<vector<string>> relation) {
    vector<string> v(relation.size(), "");
    getSuperKey(0, 0, v, relation);
    getCandidatekey();
    return candidateKey.size();
}
