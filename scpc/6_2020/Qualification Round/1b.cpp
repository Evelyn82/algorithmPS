#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
using ll=long long;

const int MAXN=3e3+1;
bool game[MAXN][MAXN];
ll arr1[MAXN], arr2[MAXN], cs1[MAXN], cs2[MAXN]; // cs->cumulative sum
int rowRL[MAXN], colRL[MAXN]; // RL->the recent lose's place(point)
int n,k,win, lose;
void firstRow(){
    for(int i=1;i<=n;++i){
        if(game[0][i-1]==false) {game[0][i]=true; win++;}
        else{
            if(rowRL[0]!=-1 && cs1[i]-cs1[rowRL[0]]<=k) {game[0][i]=true; win++;}
            else {
                rowRL[0]=i; colRL[i]=0;
                lose++;
                
            }
        }
    }
}
void firstCol(){
    for(int j=1;j<=n;++j){
        if(game[j-1][0]==false) {game[j][0]=true; win++;}
        else{
            if(colRL[0]!=-1 && cs2[j]-cs2[colRL[0]]<=k) {game[j][0]=true; win++;}
            else {
                colRL[0]=j; rowRL[j]=0;
                lose++;
                
            }
        }
    }
}
void solve(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(game[i-1][j]==false || game[i][j-1]==false) {game[i][j]=true; win++;}
            else{
                if(rowRL[i]!=-1 && cs1[j]-cs1[rowRL[i]]<=k) {game[i][j]=true; win++;}
                else if(colRL[j]!=-1 && cs2[i]-cs2[colRL[j]]<=k) {game[i][j]=true; win++;}
                else {rowRL[i]=j; colRL[j]=i; lose++;}
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        cin>>n>>k;
        
        cs1[0]=cs2[0]=0;
        for(int i=0;i<n;++i) {
            cin>>arr1[i];
            cs1[i+1]=cs1[i]+arr1[i];
        }
        for(int i=0;i<n;++i) {
            cin>>arr2[i];
            cs2[i+1]=cs2[i]+arr2[i];
        }
        
        win=lose=0;
        memset(game, false, sizeof(game));
        game[0][0]=true; win++;
        for(int i=0;i<=n;++i) rowRL[i]=colRL[i]=-1;
        
        firstRow();
        firstCol();
        solve();
        cout<<"Case #"<<tc<<'\n';
        cout<<win<<' '<<lose<<'\n';
    }
}
