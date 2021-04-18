#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        string s; cin>>s;
        
        printf("Case #%d: ",tc);
        int prev=0;
        for(int i=0;i<s.size();++i){
            int var=prev-(int)(s[i]-'0');
            for(int j=1;j<=abs(var);++j){
                if(var<0) printf("(");
                else printf(")");
            }
            prev=(int)(s[i]-'0');
            printf("%d", prev);
        }
        for(int j=1;j<=prev;++j) printf(")");
        printf("\n");
    }
}
