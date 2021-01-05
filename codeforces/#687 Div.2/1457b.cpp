//
//  1457b.cpp
//  codeforces
//
//  Created by Evelyn 💚 on 2021/01/05.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=1e5+1;
int arr[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        for(int i=0;i<n;++i) cin>>arr[i];
        
        int ret=MAXN+1;
        for(int i=1;i<=100;++i){
            int cnt=0;
            for(int j=0;j<n;++j){
                if(arr[j]!=i){
                    j+=(k-1);
                    cnt++;
                }
            }
            ret=min(ret, cnt);
        }cout<<ret<<'\n';
    }
}
