#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

struct Point{
    ll x,y;
    ll p,q;
    Point() : x(0), y(0), p(0), q(0){}
    Point(ll _x, ll _y) : x(_x), y(_y), p(0), q(0) {}
};
bool cmp(const Point &a, const Point &b){
    if(b.q*a.p != a.q*b.p) return b.q*a.p > a.q*b.p;
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
bool ccw(const Point &a, const Point &b, const Point &c){
    pll ab=make_pair(b.x-a.x, b.y-a.y);
    pll ac=make_pair(c.x-a.x, c.y-a.y);
    
    if(ab.first*ac.second-ab.second*ac.first>0) return true;
    return false;
}
int main(){
    int n; scanf("%d", &n);
   
    vector<Point> v;
    ll a, b; char c;
    for(int i=0;i<n;++i){
        scanf("%lld%lld%c", &a, &b, &c);
        if(c=='Y') v.push_back(Point(a,b));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<v.size();++i){
        v[i].p=v[i].x-v[0].x;
        v[i].q=v[i].x-v[0].y;
    }
    sort(v.begin()+1, v.end(), cmp);
    
    stack<int> st;
    st.push(0); st.push(1);
    int nxt=2;
    while(nxt<v.size()){
        while(st.size()>1){
            int one, two;
            two=st.top(); st.pop();
            one=st.top();
            if(ccw(v[one], v[two], v[nxt])){
                st.push(two); break;
            }
        }st.push(nxt++);
    }
    
    printf("%d\n", (int)v.size());
    vector<int> vt;
    while(!st.empty()){
        vt.push_back(st.top()); st.pop();
    }
    for(int &i : vt) printf("%lld %lld\n", v[i].x, v[i].y);
}
