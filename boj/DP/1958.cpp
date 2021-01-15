// 0ms
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=101;
int d[2][MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    char a[MAXN], b[MAXN], c[MAXN];
    cin>>a+1>>b+1>>c+1;
   
    int ret=0;
    int idx=0, j,k;
    for(int i=1;a[i];++i){
        for(j=1;b[j];++j){
            for(k=1;c[k];++k){
                if(a[i]==b[j] && b[j]==c[k]){
                    d[idx][j][k]=d[idx^1][j-1][k-1]+1;
                    ret=max(ret, d[idx][j][k]);
                }
                else d[idx][j][k]=max(d[idx^1][j][k], max(d[idx][j-1][k], d[idx][j][k-1]));
            }
        }idx^=1;
    }cout<<d[idx^1][j-1][k-1]<<'\n';
}

// 4ms
/*
const int MAXN=101;
int d[MAXN][MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    char a[MAXN], b[MAXN], c[MAXN];
    cin>>a+1>>b+1>>c+1;
   
    int i,j,k;
    for(i=1;a[i];++i){
        for(j=1;b[j];++j){
            for(k=1;c[k];++k){
                if(a[i]==b[j] && b[j]==c[k]){
                    d[i][j][k]=d[i-1][j-1][k-1]+1;
                }
                else d[i][j][k]=max(d[i-1][j][k], max(d[i][j-1][k], d[i][j][k-1]));
            }
        }
    }cout<<d[i-1][j-1][k-1]<<'\n';
}
*/
