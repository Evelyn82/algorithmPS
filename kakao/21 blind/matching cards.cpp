#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define mp make_pair
using namespace std;
using pii=pair<int,int>;

int dist[4][4];
int dx[]={0,0,1, -1}, dy[]={-1, 1, 0,0};
struct Card{
    int cost, x, y;
    Card(int _x, int _y) : x(_x), y(_y){}
    Card(int _cost, int _x, int _y) : cost(_cost), x(_x), y(_y){}
};
bool operator<(const Card& a, const Card& b){return a.cost>b.cost;}
bool inRange(int x, int y, int sz){
    if(x<0||x>=sz||y<0||y>=sz) return false;
    return true;
}
bool isEmpty(const vector<vector<int>>& board){
    for(int i=0;i<4;++i) for(int j=0;j<4;++j) if(board[i][j]) return false;
    return true;
}
int getDist(const vector<vector<int>>& board, pii start, pii finish){
    for(int i=0;i<4;++i) for(int j=0;j<4;++j) dist[i][j]=1e9;
    priority_queue<Card> pq;
    pq.push(Card(0, start.first, start.second));
    dist[start.first][start.second]=0;
    
    while(!pq.empty()){
        Card now=pq.top(); pq.pop();
        
        if(now.cost>dist[now.x][now.y]) continue;
        if(now.x==finish.first && now.y==finish.second) return dist[finish.first][finish.second];
        
        for(int i=0;i<4;++i){
            Card nxt=Card(now.x, now.y);
            
            int cnt=0, nxtCost;
            while(inRange(nxt.x+dx[i], nxt.y+dy[i], (int)board.size())){
                nxt.x+=dx[i]; nxt.y+=dy[i];
                if(board[nxt.x][nxt.y]) break;
                
                nxtCost=now.cost+(++cnt);
                if(dist[nxt.x][nxt.y]<nxtCost) continue;
                
                dist[nxt.x][nxt.y]=nxtCost;
                pq.push(Card(dist[nxt.x][nxt.y], nxt.x, nxt.y));
            }
    
            if(dist[nxt.x][nxt.y]>now.cost+1){
                dist[nxt.x][nxt.y]=now.cost+1;
                nxt.cost=dist[nxt.x][nxt.y];
                pq.push(nxt);
            }
            
        }
    }
}
int backTracking(vector<vector<int>>& board, int r, int c){
    if(isEmpty(board)) return 0;
    
    int answer=1e9;
    for(int k=1;k<7;++k){
        pii card1=mp(-1,-1), card2=mp(-1,-1);
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                if(board[i][j]==k){
                    if(card1.first==-1) card1=mp(i,j);
                    else card2=mp(i,j);
                }
            }
        }if(card1.first==-1) continue;
        
        int dist1=getDist(board, mp(r,c), card1)+getDist(board, card1, card2)+2;
        int dist2=getDist(board, mp(r,c), card2)+getDist(board, card2, card1)+2;
        board[card1.first][card1.second]=0;
        board[card2.first][card2.second]=0;
        
        dist1+=backTracking(board, card2.first, card2.second);
        dist2+=backTracking(board, card1.first, card1.second);
        
        answer=min(answer, min(dist1, dist2));
        
        board[card1.first][card1.second]=k;
        board[card2.first][card2.second]=k;
    }return answer;
}
int solution(vector<vector<int>> board, int r, int c) {
    return backTracking(board, r, c);
}
