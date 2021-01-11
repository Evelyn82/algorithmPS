//
//  6549.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN=1e5+1;
int n;
ll ret, h[MAXN];
ll solve(int left, int right){
    if(left==right){
        ret=max(ret, h[left]);
        return h[left];
    }
    
    int mid=(left+right)/2;
    ll mh=min(solve(left, mid), solve(mid+1, right));
    ret=max(ret, mh*(right-left+1));
    
    ll mdh=min(h[mid], h[mid+1]);
    if(mh<mdh){
        int low=mid, high=mid+1;
        while(low-1>=0 && h[low-1]>=mdh) low--;
        while(high+1<=right && h[high+1]>=mdh)high++;
        ret=max(ret, mdh*(high-low+1));
    }
    return mh;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>n){
        if(n==0) break;
        for(int i=0;i<n;++i) cin>>h[i];
        ret=0;
        solve(0, n-1);
        cout<<ret<<'\n';
    }
}
