//
//  11049.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/23.
//

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const int MAXN=510;
int arr[MAXN][2], d[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    for(int i=1;i<=n;++i) cin>>arr[i][0]>>arr[i][1];
    
    for(int i=1;i<n;++i){
        d[i][i+1]=arr[i][0]*arr[i][1]*arr[i+1][1];
    }
    
    for(int m=2;m<=n;++m){
        for(int i=1;i<=n-m;++i){
            int j=i+m;
            
            d[i][j]=987654321;
            for(int k=i;k<j;++k){
                int ret=d[i][k]+d[k+1][j]+(arr[i][0]*arr[k][1]*arr[j][1]);
                d[i][j]=min(d[i][j], ret);
            }
        }
    }cout<<d[1][n]<<'\n';
}
