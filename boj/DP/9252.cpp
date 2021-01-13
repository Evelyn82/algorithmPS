// 4ms
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=1e3+1;
int d[2][MAXN], dp[MAXN][MAXN];
char a[MAXN], b[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>a+1>>b+1;
    
    int idx=0, i, j;
    for(i=1;a[i];++i){
        for(j=1;b[j];++j){
            if(a[i]==b[j]) {
                d[idx][j]=d[idx^1][j-1]+1;
                dp[i][j]=1;
            }
            else{
                if(d[idx^1][j]>=d[idx][j-1]){
                    d[idx][j]=d[idx^1][j];
                    dp[i][j]=2;
                }
                else{
                    d[idx][j]=d[idx][j-1];
                    dp[i][j]=3;
                }
            }
        }idx^=1;
    }
    cout<<d[idx^1][j-1]<<'\n';

    a[1000]='\0';
    idx=999;
    --i, --j;
    while(dp[i][j] && (i>0||j>0)){
        if(dp[i][j]==1){
            a[idx--]=b[j];
            --i, --j;
        }
        else if(dp[i][j]==2) --i;
        else if(dp[i][j]==3) --j;
    }
    cout<<a+idx+1<<'\n';
}

// 32ms
/*
const int MAXN=10001;
char c1[MAXN], c2[MAXN];
int d[2][MAXN];
string sd[2][MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>c1+1>>c2+1;
    
    int idx=0, j;
    for(int i=1;c1[i];++i){
        for(j=1;c2[j];++j){
            if(c1[i]==c2[j]){
                d[idx][j] = d[idx^1][j-1]+1;
                sd[idx][j] =sd[idx^1][j-1]+c1[i];
            }
            else {
                if(d[idx][j-1]> d[idx^1][j]){
                    d[idx][j]=d[idx][j-1];
                    sd[idx][j]=sd[idx][j-1];
                }else{
                    d[idx][j]=d[idx^1][j];
                    sd[idx][j]=sd[idx^1][j];
                }
            }
        }
        idx^=1;
    }
    cout<<sd[idx^1][j-1].size()<<'\n';
    cout<<sd[idx^1][j-1]<<'\n';
}

*/
