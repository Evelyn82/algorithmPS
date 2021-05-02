#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define mp make_pair
using namespace std;
using pii=pair<int,int>;

vector<int> xpos[51];
set<int> blockSt;
pii fillArea[201];
vector<vector<int>> adj;
vector<int> indegree;
vector<bool> breakable;
bool vstPath[201][201];
vector<pii> breakPos[5]={
    {{1,0},{1,1},{1,2}},
    {{1,0},{2,0},{2,-1}},
    {{1,0},{2,0},{2,1}},
    {{1,0},{1,-1},{1,-2}},
    {{1,0},{1,-1}, {1,1}}
};

void setFillArea(int x, int y, int idx, const vector<vector<int>>& board){
    if(idx==0) fillArea[board[x][y]]=mp(y+1, y+2);
    else if(idx==1) fillArea[board[x][y]]=mp(y-1, y-1);
    else if(idx==2) fillArea[board[x][y]]=mp(y+1, y+1);
    else if(idx==3) fillArea[board[x][y]]=mp(y-2, y-1);
    else fillArea[board[x][y]]=mp(y-1, y+1);
}
void findUnbreakable(const vector<vector<int>>& board){
    int sz=board.size();
    vector<bool> vst(201, false);
    for(int i=0;i<sz-1;++i){
        for(int j=0;j<sz;++j){
            int num=board[i][j];
            if(num && !vst[num]){
                vst[num]=true;
                int nx, ny, k, l;
                bool flag=false;
                for(k=0;k<5;++k){
                    for(l=0;l<3;++l){
                        nx=i+breakPos[k][l].first, ny=j+breakPos[k][l].second;
                        if(nx<0||nx>=sz||ny<0||ny>=sz) break;
                        if(board[nx][ny]!=num) break;
                    }
                    if(l==3) {
                        flag=true;
                        setFillArea(i, j, k, board);
                        breakable[board[i][j]]=true;
                        break;
                    }
                }
            }
        }
    }
}

int topologicalSort(const vector<vector<int>>& board){
    adj.resize(201);
    indegree.resize(201, 0);
    for(int j=0;j<51;++j){
        if(xpos[j].size()<2) continue;
        for(int i=0;i<xpos[j].size()-1;++i){
            int from=board[xpos[j][i]][j], to=board[xpos[j][i+1]][j];
            if(breakable[from]) {
                if(!vstPath[from][to]){
                    adj[from].push_back(to);
                    vstPath[from][to]=true;
                    indegree[to]++;
                }
            }
            else {
                if(!breakable[to]){
                    if(!vstPath[from][to]){
                        adj[from].push_back(to);
                        vstPath[from][to]=true;
                        indegree[to]++;
                    }
                }
                else{
                    if(fillArea[to].first==j||fillArea[to].second==j) {
                        if(!vstPath[from][to]){
                            adj[from].push_back(to);
                            vstPath[from][to]=true;
                            indegree[to]++;
                        }
                    }
                }
            }
        }
    }
    
    set<int> startPoint;
    for(int j=0;j<51;++j) {
        if(xpos[j].empty()) continue;
        int x=xpos[j][0];
        if(indegree[board[x][j]]==0) {
            if(!breakable[board[x][j]]) continue;
            startPoint.insert(board[x][j]);
        }
    }
    queue<int> q;
    for(auto it : startPoint) q.push(it);
    
    int answer=0;
    while(!q.empty()){
        int now=q.front(); q.pop();
        answer++;
        
        for(int i=0;i<adj[now].size();++i){
            int nxt=adj[now][i];
            if(!breakable[nxt]) continue;
            if(--indegree[nxt]==0){
                q.push(nxt);
            }
        }
    }return answer;
}
int solution(vector<vector<int>> board) {
    breakable.resize(201, false);
    int sz=board.size();
    for(int j=0;j<sz;++j){
        for(int i=0;i<sz;++i){
            if(board[i][j]){
                if(xpos[j].empty() || board[xpos[j].back()][j]!=board[i][j]) xpos[j].push_back(i);
            }
        }
    }
    findUnbreakable(board);
    return topologicalSort(board);
}
