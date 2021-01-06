//
//  dp.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/06.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXS=1e3+1;
string s1, s2;
int dp[MAXS][MAXS];
int solve(int a, int b){
    int& ref=dp[a][b];
    if(ref!=-1) return ref;
   
    ref=0;
    if(a==s1.length()||b==s2.length()) return ref;
    
    if(a<s1.length()&& b<s2.length() && s1[a]==s2[b]) return ref=solve(a+1, b+1)+1;
    
    // 316ms
    /*
    for(int k=b;k<s2.length();++k){
        if(s1[a]==s2[k]) ref=max(ref, solve(a+1, k+1)+1);
    }
    ref=max(ref, solve(a+1,b));
     */
    
    // 12ms
    ref=max(solve(a+1,b), solve(a, b+1));
    return ref;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>s1>>s2;
    
    for(int i=0;i<s1.length();++i){
        for(int j=0;j<s2.length();++j) dp[i][j]=-1;
    }
    cout<<solve(0,0)<<'\n';
}
