//
//  1437b.cpp
//  codeforces
//
//  Created by Evelyn 💚 on 2020/12/28.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        
        int one=0;
        for(int i=1;i<n;++i){
            if(s[i]=='1' && s[i+1]=='1') one++;
        }
        
        int zero=0;
        for(int i=1;i<n;++i){
            if(s[i]=='0' && s[i+1]=='0') zero++;
        }
        
        cout<<max(one,zero)<<'\n';
    }
}
