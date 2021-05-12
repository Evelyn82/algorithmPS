//  https://www.acmicpc.net/blog/view/12
//  108ms
//  6549.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/11.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

void init(vector<int>& arr, vector<int>& rmh, int node, int left, int right){
    if(left==right) {
        rmh[node]=left;
        return ;
    }
    int mid=(left+right)/2;
    init(arr, rmh, node*2, left, mid);
    init(arr, rmh, node*2+1, mid+1, right);
    if(arr[rmh[node*2]]<=arr[rmh[node*2+1]]) rmh[node]=rmh[node*2];
    else rmh[node]=rmh[node*2+1];
}
int query(vector<int>& arr, vector<int>& rmh, int left, int right, int node, int nodeleft, int noderight){
    if(right<nodeleft||noderight<left) return -1;
    if(left<=nodeleft && noderight<=right) return rmh[node];
    
    int mid=(nodeleft+noderight)/2;
    int low=query(arr, rmh, left, right, node*2, nodeleft, mid);
    int high=query(arr, rmh, left, right, node*2+1, mid+1, noderight);
    if(low==-1) return high;
    if(high==-1) return low;
    if(arr[low]<=arr[high]) return low;
    return high;
}
ll largest(vector<int>& arr, vector<int>& rmh, int left, int right){
    int n=(int)arr.size();
    int m=query(arr, rmh, left, right,1, 0, n-1);
    
    ll ret=(ll)(right-left+1)*(ll)arr[m];
    if(left<=m-1) ret=max(ret, largest(arr, rmh, left, m-1));
    if(m+1<=right) ret=max(ret, largest(arr, rmh, m+1, right));
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    while(cin>>n){
        if(n==0) break;
        vector<int> arr(n);
        for(int i=0;i<n;++i) cin>>arr[i];
        
        int sz=(int)(ceil(log2(n))+1e-9);
        int hsz=(1<<(sz+1));
        vector<int> rmh(hsz, 0);  // range min height
        init(arr, rmh, 1, 0, n-1);
        cout<<largest(arr, rmh, 0, n-1)<<'\n';
    }
}
