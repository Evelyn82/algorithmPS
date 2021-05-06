#include <string>
#include <vector>

using namespace std;

struct Point{
    bool beam, pillar;
    Point() :beam(false), pillar(false) {}
};
Point board[101][101];
void install(int x, int y, int state){
    if(state){  //beam
        if(y && board[x][y-1].pillar) { // 바로 아래에 기둥이 있는 경우
            board[x][y].beam=true;
        }
        else if(board[x+1][y-1].pillar){ // 오른쪽 아래에 기둥이 있는 경우
            board[x][y].beam=true;
        }
        else if((x&&board[x-1][y].beam) && board[x+1][y].beam){ // 양쪽에 보가 있는 경우
            board[x][y].beam=true;
        }
    }
    else{   // pillar
        if(y==0) { // 바닥에 설치
            board[x][y].pillar=true;
        }
        else if(y && board[x][y-1].pillar) { // 아래 기둥에 설치
            board[x][y].pillar=true;
        }
        else if(board[x][y].beam || (x && board[x-1][y].beam)){ // 양쪽에 보가 1개라도 있는 경우
            board[x][y].pillar=true;
        }
    }
}
void uninstall(int x, int y, int state){
    if(state){ // beam
        if(board[x-1][y].beam && board[x+1][y].beam){
            if(board[x][y-1].pillar || board[x+1][y-1].pillar) return;
        }
        if(x && board[x-1][y].beam){
            if(!board[x-1][y-1].pillar && !board[x][y-1].pillar) return;
        }
        if(board[x+1][y].beam){
            if(!board[x+1][y-1].pillar && !board[x+1][y-1].pillar) return;
        }
        board[x][y].beam=false;
    }
    else{
        if(x && board[x-1][y+1].beam) { // 왼쪽에 보가 있는 경우
            if(!board[x-1][y].pillar){ // 왼쪽 보 밑에 기둥이 없는 경우
                if(x==1) return; // 더이상 왼쪽 보를 탐색할 수 없을 때
                if(x>1 && !board[x-2][y+1].beam) return; // 왼쪽보의 왼쪽보가 존제하는 경우
            }
        }
        if(board[x][y+1].beam){ // 삭제하려는 기둥 위에 보가 있는 경우
            if(board[x+1][y+1].beam){
                if(x+2<sz && !board[x+2][y+1].beam){
                     if(!board[x+1][y].pillar && !board[x+2][y].pillar) return;
                }
            }
            else {
                if(!board[x+1][y].pillar) return;
            }
        }
        board[x][y].pillar=false;
    }
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for(vector<int>& v : build_frame){
        if(v[3]) install(v[0], v[1], v[2]);
        else uninstall(v[0], v[1], v[2]);
    }
    vector<vector<int>> answer;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            if(board[i][j].pillar) {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                v.push_back(0);
                answer.push_back(v);
            } 
            if(board[i][j].beam) {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                v.push_back(1);
                answer.push_back(v);
            } 
        }
    }return answer;
}
