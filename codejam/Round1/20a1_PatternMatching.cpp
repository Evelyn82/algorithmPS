#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> s;
string solve(){
    string pf="", mid="", sf="";
    for(int i=0;i<s.size();++i){
        //prefix
        int p;
        for(p=0;p<s[i].length();++p){
            if(s[i][p]=='*') break;
            if(pf.length()==p) pf+=s[i][p];
            else if(pf[p]!=s[i][p]) return "*";
        }

        //suffix
        int ss, c=0;
        for(ss=(int)s[i].length()-1;ss>=0;--ss, ++c){
            if(s[i][ss]=='*') break;
            if(sf.length()==c)sf+=s[i][ss];
            else if(sf[c]!=s[i][ss]) return "*";
        }
        
        //mid
        for(;p<ss;++p){
            if(s[i][p]!='*') mid.push_back(s[i][p]);
        }
    }
    reverse(sf.begin(), sf.end());
    return pf+mid+sf;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        int n; cin>>n;
        s.clear(); s.resize(n);
        for(int i=0;i<n;++i) cin>>s[i];
        
        cout<<"Case #"<<tc<<": ";
        cout<<solve()<<'\n';
    }
}
