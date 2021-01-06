// 4ms
//
//  11054.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=1e3+1;
int arr[MAXN];
int incr[MAXN], decr[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    for(int i=0;i<n;++i) cin>>arr[i];
    
    // increase
    for(int i=0;i<n;++i){
        incr[i]=1;
        for(int j=0;j<i;++j){
            if(arr[j]<arr[i]) incr[i]=max(incr[i], incr[j]+1);
        }
    }
    // decrease
    for(int i=n-1;i>=0;--i){
        decr[i]=1;
        for(int j=n-1;j>=0;--j){
            if(arr[i]>arr[j]) decr[i]=max(decr[i], decr[j]+1);
        }
    }
    
    int ans=0;
    for(int i=0;i<n;++i){
        ans=max(ans, incr[i]+decr[i]-1);
    }cout<<ans<<'\n';
}
