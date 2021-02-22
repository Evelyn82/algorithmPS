#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll DIV=1e9;

string s;
pll solve(int low, int high){
    int x=0, y=0;
    for(int i=low;i<=high;++i){
        if(s[i]>='2' && s[i]<='9'){
            int open=1, endIdx=i+2;
            while(open){
                if(s[endIdx]=='(') open++;
                else if(s[endIdx]==')') open--;
                endIdx++;
            }
            pll subF=solve(i+2, endIdx-2);
            x=(x+(int)(s[i]-'0')*subF.first)%DIV;
            y=(y+(int)(s[i]-'0')*subF.second)%DIV;
            i=endIdx-1;
            //continue;
        }
        else if(s[i]=='N') y=(y+DIV-1)%DIV;
        else if(s[i]=='S') y=(y+DIV+1)%DIV;
        else if(s[i]=='W') x=(x+DIV-1)%DIV;
        else if(s[i]=='E') x=(x+DIV+1)%DIV;
    }
    
    return make_pair(x, y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        cin>>s;
        pll ret=solve(0, (int)s.size()-1);
        cout<<"Case #"<<tc<<": "<<ret.first%DIV+1<<' '<<ret.second%DIV+1<<'\n';
    }
}
