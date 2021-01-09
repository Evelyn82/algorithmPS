//  892ms
//  11658.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/10.
//

/*
struct로 작성시 -> TLE
struct Fenwick{
    int n;
    vector<vector<int>> fw;
    
    Fenwick(int _n) : n(_n) {
        fw.resize(n+1,vector<int>(n+1,0));
    }
    int sum(int x, int y){
        int ret=0;
        while(y>=1){
            ret+=fw[x][y];
            y-=(y&-y);
        }return ret;
    }
    void add(int x, int y, ll diff){
        while(y<=n){
            fw[x][y]+=diff;
            y+=(y&-y);
        }
    }
};
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=1025;
int arr[MAXN][MAXN];
int fw[MAXN][MAXN];
int n,m;
int sum(int x, int y){
    int ret=0;
    while(y>=1){
        ret+=fw[x][y];
        y-=(y&-y);
    }return ret;
}
void add(int x, int y, int diff){
    while(y<=n){
        fw[x][y]+=diff;
        y+=(y&-y);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n>>m;
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) {
            cin>>arr[i][j];
            add(i, j, arr[i][j]);
        }
    }
        
    int w, a, b, c,d;
    for(int i=0;i<m;++i){
        cin>>w;
        if(w){
            cin>>a>>b>>c>>d;
            //if(a>c) swap(a,c);
            int ret=0;
            for(int j=a;j<=c;++j){
                ret+=sum(j,d)-sum(j, b-1);
            }cout<<ret<<'\n';
        }
        else{
            cin>>a>>b>>c;
            add(a,b, c-arr[a][b]);
            arr[a][b]=c;
        }
    }
}

