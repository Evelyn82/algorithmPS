#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll=long long;
const int MXR=1e5+5;

struct Square{
    int x, y, idx, skill;
    int vst;
    Square(){}
    Square(int _x, int _y, int _idx, int _skill):x(_x), y(_y), idx(_idx), skill(_skill), vst(0){}
}arr[MXR];
int r, c;
vector<set<int>> row, col;
void solve(queue<int>& q, ll initialSum){
    ll ret=initialSum, tmpRet=initialSum;
    set<int> delList;
    int order=1;
    while(1){
        while(!q.empty()){
            int now=q.front(); q.pop();
            if(arr[now].vst==order) continue;
            arr[now].vst=order;
            int x=arr[now].x, y=arr[now].y;
            
            ll sum=0; int cnt=0;
            
            // row greater than
            auto rgt=row[x].upper_bound(now);
            if(rgt!=row[x].end()) {sum+=arr[*rgt].skill; cnt++;}
            
            // row less than
            auto rlt=row[x].lower_bound(now);
            if(rlt!=row[x].begin()) {sum+=arr[*(--rlt)].skill; cnt++;}
            
            // col greater than
            auto cgt=col[y].upper_bound(now);
            if(cgt!=col[y].end()) {sum+=arr[*cgt].skill; cnt++;}
            
            // col less than
            auto clt=col[y].lower_bound(now);
            if(clt!=col[y].begin()) {sum+=arr[*(--clt)].skill; cnt++;}
            
            if(arr[now].skill*cnt<sum) {
                delList.insert(now);
                tmpRet-=arr[now].skill;
            }
        }
        if(delList.size()==0) break;
        ret+=tmpRet;
        
        order++;
        for(int now : delList){
            if(arr[now].vst==order) continue;
            arr[now].vst=order;
            int x=arr[now].x, y=arr[now].y;
            row[x].erase(row[x].find(now));
            col[y].erase(col[y].find(now));
            //row[x].erase(now);
            //col[y].erase(now);
        }
        
        order++;
        for(int now : delList){
            if(arr[now].vst==order) continue;
            arr[now].vst=order;
            int x=arr[now].x, y=arr[now].y;
            
            // row direction
            auto rd=row[x].upper_bound(now);
            if(rd!=row[x].end()) q.push(*rd);
            if(rd!=row[x].begin()) q.push(*(--rd));
            
            // column direction
            auto cd=col[y].upper_bound(now);
            if(cd!=col[y].end()) q.push(*cd);
            if(cd!=col[y].begin()) q.push(*(--cd));
        }
        delList.clear();
    }
    cout<<ret<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;tc++){
        int r, c; cin>>r>>c;
        
        row.clear(); row.resize(r);
        col.clear(); col.resize(c);
        queue<int> q;
        int idx=0, skill; ll sum=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                cin>>skill;
                sum+=skill;
                arr[idx]=Square(i, j, idx, skill);
                row[i].insert(idx);
                col[j].insert(idx);
                q.push(idx++);
            }
        }
        cout<<"Case #"<<tc<<": ";
        solve(q, sum);
    }
}
