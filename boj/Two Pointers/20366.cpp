#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> h;
struct Point{
    int x, y;
    Point(int _x, int _y):x(_x), y(_y){}
    
    bool operator<(const Point& other){
        return h[x]+h[y] < h[other.x]+h[other.y];
    }
};
vector<Point> point;
bool isSamePoint(const Point& a, const Point& b){
    return a.x==b.x || a.x==b.y || a.y==b.x || a.y==b.y;
}
int getDiff(const Point& a, const Point& b){
    return abs(h[a.x] + h[a.y] - h[b.x] - h[b.y]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin>>N;
    h.resize(N);
    for(int i=0;i<N;++i) cin>>h[i];
    sort(h.begin(), h.end());
    
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j) point.emplace_back(i, j);
    }sort(point.begin(), point.end());
    
    int answer=INT_MAX;
    for(int i=0;i<point.size()-1;++i){
        if(!isSamePoint(point[i], point[i+1])){
            answer=min(answer, getDiff(point[i], point[i+1]));
        }
    }cout<<answer<<'\n';
}
