#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char board[5][5];
int dx[]={0,0,1, -1}, dy[]={1,-1, 0,0};
bool path[33554432];
int answer;
void backTracking(int state, int total, int scnt){
    path[state]=true;
    if(3+scnt<total) return;
    if(total==7){
        if(scnt>=4) answer++;
        return;
    }
    int x, y, nx, ny, nxt;
    for(int i=0;i<25;++i){
        if(!(state & (1<<i))) continue;
        x=i/5; y=i%5;
        for(int j=0;j<4;++j){
            nx=x+dx[j], ny=y+dy[j];
            if(nx<0 || nx>4 || ny<0 || ny>4) continue;
            
            nxt=nx*5+ny;
            if(path[state|(1<<nxt)] || (state & (1<<nxt))) continue;
           
            if(board[nx][ny]=='S') backTracking(state|(1<<nxt), total+1, scnt+1);
            else backTracking(state|(1<<nxt), total+1, scnt);
        }
    }
}
int main(){
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            scanf(" %c", &board[i][j]);
        }
    }
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            int state=i*5+j;
            if(board[i][j]=='S') backTracking(1<<state, 1, 1);
            else backTracking(1<<state, 1, 0);
        }
    }printf("%d\n", answer);
}
