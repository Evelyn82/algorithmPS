#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN=1e6+1;
struct Candy{
    //int n;
    vector<int> rsq;
    
    Candy() {
        rsq.resize(4*MAXN, 0);
    }
    void ppc(int nodeleft, int noderight, int rank, int node){
        if(nodeleft==noderight){
            cout<<nodeleft<<'\n';
            pushCandy(nodeleft, -1);
            return;
        }
        
        int mid=(nodeleft+noderight)/2;
        if(rsq[node*2]>=rank) ppc(nodeleft, mid, rank, node*2);
        else ppc(mid+1, noderight, rank-rsq[node*2], node*2+1);
    }
    void popCandy(int rank){
        ppc(1, MAXN, rank,1);
    }
    int phc(int nodeleft, int noderight, int idx, int cnt, int node){
        if(idx<nodeleft ||  noderight<idx) return rsq[node];
        if(nodeleft==noderight) return rsq[node]+=cnt;
        
        int mid=(nodeleft+noderight)/2;
        return rsq[node]=phc(nodeleft, mid,idx, cnt, node*2)+phc(mid+1, noderight, idx, cnt, node*2+1);
    }
    void pushCandy(int idx, int cnt){
        phc(1, MAXN, idx, cnt, 1);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    
    Candy* node=new Candy();
    int a,b,c;
    while(n--){
        cin>>a;
        if(a==1){
            cin>>b;
            node->popCandy(b);
        }
        else{
            cin>>b>>c;
            node->pushCandy(b, c);
        }
    }
}
