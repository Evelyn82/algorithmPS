#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define mp make_pair
using namespace std;
using pii=pair<int,int>;

char board[5][5];
bool point[5][5], vst[5][5];
int dx[]={0,0,1,-1}, dy[]={1, -1, 0,0};
int answer;
void bfs(int x, int y){
    queue<pii> q;
    q.push(mp(x,y));
    vst[x][y]=true;
    int vstPoint=1, scnt=0;
    
    while(!q.empty()){
        pii now=q.front(); q.pop();
        
        if(board[now.first][now.second]=='S') scnt++;
        for(int i=0;i<4;++i){
            int nx=now.first+dx[i];
            int ny=now.second+dy[i];
            
            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            if(!vst[nx][ny] && point[nx][ny]){
                vst[nx][ny]=true;
                vstPoint++;
                q.push(mp(nx, ny));
            }
        }
    }if(vstPoint==7 && scnt>=4) answer++;
}
int main(){
    char skip;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            scanf("%1c", &board[i][j]);
        }scanf("%1c",&skip);
    }
    vector<int> order(25,0);
    for(int i=24;i>17;--i) order[i]=1;
    do{
        int x, y;
        for(int i=0;i<5;++i) for(int j=0;j<5;++j) {vst[i][j]=false; point[i][j]=false; }
        for(int i=0;i<25;++i){
            if(order[i]){
                x=i/5;
                y=i%5;
                point[x][y]=true;
            }
        }bfs(x, y);
    }while(next_permutation(order.begin(), order.end()));
    printf("%d\n", answer);
}
