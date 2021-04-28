#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<int> st;
vector<bool> vst; // user standard
void dfs(const vector<string>& user_id, const vector<string>& banned_id, int bidx, int num){
    if(bidx==banned_id.size()){
        st.emplace(num);
        return;
    }
    
    for(int i=0;i<user_id.size();++i){
        if(vst[i]) continue;
        if(banned_id[bidx].size() != user_id[i].size()) continue;
        
        int j;
        for(j=0;j<banned_id[bidx].size();++j){
            if(banned_id[bidx][j]=='*') continue;
            if(banned_id[bidx][j]!=user_id[i][j]) break;
        }
        
        if(j==banned_id[bidx].size()){
            vst[i]=true;
            dfs(user_id, banned_id, bidx+1, num | (1<<i));
            vst[i]=false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    vst.resize(user_id.size(), false);
    dfs(user_id, banned_id, 0, 0);
    return (int)st.size();
}
