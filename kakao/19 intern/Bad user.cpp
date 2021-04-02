// 81.8/100

#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

bool d[9][9], path[9][9], vst[9];
int answer, bansz, usersz;
bool sameChk(const string& a, const string& b){
    if(a.size()!=b.size()) return false;
    for(int i=0;i<a.size();++i){
        if(a[i]=='*') continue;
        if(a[i]!=b[i]) return false;
    }return true;
}
void dfs(int depth, int now, const vector<string>& v){
    if(depth==bansz) {
        answer++; return;
    }
    
    for(int i=0;i<usersz;++i){
        if(!d[depth][i] || vst[i]) continue;
        if(v[depth-1]==v[depth] && path[i][now]) continue;
        path[now][i]=true;
        vst[i]=true;
        dfs(depth+1, i, v);
        vst[i]=false;
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    usersz=(int)user_id.size();
    bansz=(int)banned_id.size();
    sort(banned_id.begin(), banned_id.end());
    for(int i=0;i<bansz;++i){
        for(int j=0;j<usersz;++j){
            if(!sameChk(banned_id[i], user_id[j])) continue;
            d[i][j]=true;
        }
    }
    
    answer=0;
    for(int i=0;i<usersz;++i){
        if(d[0][i]){
            vst[i]=true;
            dfs(1, i, banned_id);
        }
    }
    return answer;
}
