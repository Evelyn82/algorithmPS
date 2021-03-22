#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
const int MX=2000;
const int MXN=12000;
int n, arr[MX+2];
int d[MXN+2];
bool chk(int num){
    string s=to_string(num);
    for(char c : s){
        if(c%2) return true;
    }return false;
}
int solve(){
    int ans=0;
    memset(d, 0, sizeof d);
    d[0]=1;
    for(int i=0;i<=MX;++i){
        for(int j=MXN;j>=0;--j){
            for(int k=1;k<=arr[i] && k*i <= j;++k){
                if(d[j-(k*i)]){
                    d[j]+=d[j-(k*i)];
                    if(chk(j)){
                        ans+=d[j-(k*i)];
                        cout<<j<<' '<<d[j-(k*i)]<<'\n';
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        memset(arr, 0, sizeof arr);
        cin>>n;
        int num;
        for(int i=0;i<n;++i){
            cin>>num;
            arr[num]++;
        }
        cout<<solve()<<'\n';
    }
}
