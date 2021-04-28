#include <string>
#include <vector>
#include <queue>
#define mp make_pair
using namespace std;
using pii=pair<int, int>;

int dx[]={-1, 0,0, 1}, dy[]={0,-1,1, 0};
struct Car{
    int x, y, cost, dir;
    Car() :x(0), y(0), cost(0), dir(0){}
    Car(int _x, int _y, int _cost, int _dir) : x(_x), y(_y), cost(_cost), dir(_dir){}
    
    bool operator<(const Car& other){
        return cost<other.cost;
    }
};
int solution(vector<vector<int>> board) {
    queue<Car> pq; 
    pq.push(Car(0,0,0,2));
    pq.push(Car(0,0,0,3));
    
    
    int sz=board.size();
    vector<vector<int>> dist=vector<vector<int>>(sz, vector<int>(sz,1e9));
    dist[0][0]=0;
    
    while(!pq.empty()){
        Car now=pq.front(); pq.pop();
        
        if(dist[now.x][now.y]<now.cost) continue;
        if(now.x==sz-1 && now.y==sz-1) {
            if(dist[sz-1][sz-1]>now.cost) dist[sz-1][sz-1]=now.cost;
            continue;
        }
        
        for(int i=0;i<4;++i){
            int nx=now.x+dx[i], ny=now.y+dy[i];
            if(nx<0 || nx>=sz || ny<0|| ny>=sz) continue;
            if(board[nx][ny]) continue;
            
            int nxtCost=now.cost+100;
            if(now.dir!=i  && now.dir+i!=3) nxtCost+=500;
            if(dist[nx][ny]<nxtCost) continue;
            dist[nx][ny]=nxtCost;
            pq.push(Car(nx, ny, nxtCost, i));
        }
    }
    return dist[sz-1][sz-1];
}
