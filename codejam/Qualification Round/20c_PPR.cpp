#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Schedule{
    int st, et, order;
    char c;
    Schedule(){}
    Schedule(int s, int e, int o) : st(s), et(e), order(o){}
}sch[1001];
bool cmp(const Schedule& a, const Schedule& b){
    if(a.st==b.st) return a.et<b.et;
    return a.st<b.st;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        int n; cin>>n;
        for(int i=0;i<n;++i){
            cin>>sch[i].st>>sch[i].et;
            sch[i].order=i;
            sch[i].c=NULL;
        }
        sort(sch, sch+n, cmp);
        int tep=0;
        for(int i=0;i<n;++i){
            if(tep<=sch[i].st) {
                sch[i].c='C';
                tep=sch[i].et;
            }
        }
        tep=0;
        for(int i=0;i<n;++i){
            if(!sch[i].c && tep<=sch[i].st){
                sch[i].c='J';
                tep=sch[i].et;
            }
        }
        
        sort(sch, sch+n, [&](const Schedule& a, const Schedule& b){
            return a.order<b.order;
        });
        
        string ans="";
        for(int i=0;i<n;++i){
            if(sch[i].c) ans+=sch[i].c;
            else break;
        }
        cout<<"Case #"<<tc<<": ";
        if(ans.size()==n) cout<<ans<<'\n';
        else cout<<"IMPOSSIBLE\n";
    }
}
