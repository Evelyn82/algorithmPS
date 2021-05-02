#include <string>
#include <vector>

using namespace std;

bool isEmpty(int x, int y, const vector<vector<int>>& board){
    for(int i=0;i<x;++i){
        if(board[i][y]) return false;
    }return true;
}
bool breakable(int x, int y, int szX, int szY, vector<vector<int>>& board){
    int emptyArea=0, lastNum=-1;
    for(int i=x;i<x+szX;++i){
        for(int j=y;j<y+szY;++j){
            if(board[i][j]==0){
                if(!isEmpty(i, j, board)) return false;
                if(++emptyArea>2) return false;
            }
            else{
                if(lastNum!=-1 && lastNum!=board[i][j]) return false;
                lastNum=board[i][j];
            }
        }
    }
    for(int i=x;i<x+szX;++i){
        for(int j=y;j<y+szY;++j) {
            board[i][j]=0;
        }
    }
    return true;
}
int solution(vector<vector<int>> board) {;
    int sz=board.size();
    int answer=0, cnt;
    do{
        cnt=0;
        for(int i=0;i<sz;++i){
            for(int j=0;j<sz;++j){
                if(i<=sz-3 && j<=sz-2 && breakable(i, j, 3, 2, board)) cnt++;
                else if(i<=sz-2 && j<=sz-3 && breakable(i, j, 2, 3, board)) cnt++;
            }
        }
        answer+=cnt;
    }while(cnt);
    return answer;
}

