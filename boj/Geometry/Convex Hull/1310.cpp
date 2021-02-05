#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

struct Point{
    ll x, y;
    ll p, q;
    
    Point operator - (const Point &other) const{
        return {x-other.x, y-other.y, 0, 0};
    }
    bool operator < (const Point &other) const{
        if(q*other.p != other.q*p) return q*other.p < other.q*p;
        if(x != other.x) return x<other.x;
        return y<other.y;
    }
};
ll ccw(const Point &a, const Point &b, const Point &c){
    pll ab={b.x-a.x, b.y-a.y};
    pll ac={c.x-a.x, c.y-a.y};
    return ac.second*ab.first - ab.second*ac.first;
}
ll ccw(const Point &a, const Point &b){
    return a.x*b.y - a.y*b.x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<Point> v(n);
    ll a, b;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        v.push_back(Point{a, b, 0, 0});
    }
    sort(v.begin(), v.end());
    for(int i=1;i<n;++i){
        v[i].p=v[i].x-v[0].x;
        v[i].q=v[i].y-v[0].y;
    }
    sort(v.begin()+1, v.end());
    
    vector<Point> c;
    for(Point &i : v){
        while(c.size()>1 && ccw(c[c.size()-2], c[c.size()-1], i)<=0) c.pop_back();
        c.push_back(i);
    }
    
    n=c.size();
    auto next=[n](int i){return (i+1)%n;};
    
    int left=0, right=0;
    for(int i=0;i<c.size();++i){
        if(c[left].x>c[i].x) left=i;
        if(c[right].x<c[i].x) right=i;
    }
    
    for(int i=0;i<c.size();++i){
        if(ccw(c[left], c[right])>0){
            ;
        }
    }
}
