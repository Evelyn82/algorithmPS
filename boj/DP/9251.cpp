// 0ms
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN=1e3+1;
int d[2][MAXN];
char a[MAXN], b[MAXN];
int main(){
    scanf("%s %s", a+1, b+1);
    
    int j, idx=0;
    for(int i=1;a[i];++i){
        for(j=1;b[j];++j){
            if(a[i]==b[j]) d[idx][j]=d[idx^1][j-1]+1;  // 더 정확히는 d[idx][j]=max(d[idx][j], d[idx^1][j-1]+1); 순서대로 누적되니깐 상관없다..?
            else d[idx][j]=max(d[idx][j-1], d[idx^1][j]);
        }
        idx^=1;
    }
    printf("%d\n", d[idx^1][j-1]);
}

// 12ms
/*
const int MAXS=1e3+1;
string s1, s2;
int dp[MAXS][MAXS];
int solve(int a, int b){
    int& ref=dp[a][b];
    if(ref!=-1) return ref;
   
    ref=0;
    if(a==s1.length()||b==s2.length()) return ref;
    
    if(a<s1.length()&& b<s2.length() && s1[a]==s2[b]) return ref=solve(a+1, b+1)+1;
    
    // 316ms(line 39~42)
    //for(int k=b;k<s2.length();++k){
    //    if(s1[a]==s2[k]) ref=max(ref, solve(a+1, k+1)+1);
    //}
    //ref=max(ref, solve(a+1,b));
    
    // 12ms(Change line 39~42)
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
*/
