#include <string>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> ans;
void chgBoard(const vector<vector<int>>& board){
    int sz=(int)board.size();
    v.resize(sz);
    
    for(int j=0;j<sz;++j){
        for(int i=sz-1;i>=0;--i){
            if(board[i][j]==0) continue;
            v[j].push_back(board[i][j]);
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    chgBoard(board);
    
    int answer=0;
    for(int& i : moves){
        if(v[i-1].empty()) continue;
        if(!ans.empty() && ans.back()==v[i-1].back()) {
            ans.pop_back(); answer++;
        }
        else ans.push_back(v[i-1].back());
        v[i-1].pop_back();
    }
    return answer*2;
}
