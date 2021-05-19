// boj 6549 히스토그램 동일한 방식

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=1e5;

vector<long long int> fw; // sum
vector<int> v, sg; // v(value), sg(range min value idx)
void sgUpdate(int left, int right, int node){
    if(left==right){
        sg[node]=left;
        return;
    }
    int mid=left+right>>1;
    sgUpdate(left, mid, node*2);
    sgUpdate(mid+1, right, node*2+1);
    
    if(v[sg[node*2]]<=v[sg[node*2+1]]) sg[node]=sg[node*2];
    else sg[node]=sg[node*2+1];
}
long long int query(int n){
    long long int sum=0;
    while(n){
        sum+=fw[n];
        n-=(n& -n);
    }return sum;
}
void fwUpdate(int i, long long int cost){
    while(i<fw.size()){
        fw[i]+=cost;
        i+=(i&-i);
    }
}
int findmin(int left, int right, int node, int nodeleft, int noderight){
    if(right<nodeleft || noderight<left) return -1;
    if(left<=nodeleft && noderight<=right) return sg[node];
    
    int mid=nodeleft+noderight>>1;
    int low=findmin(left, right, node*2, nodeleft, mid);
    int high=findmin(left, right, node*2+1, mid+1, noderight);
    
    if(low==-1) return high;
    if(high==-1) return low;
    if(v[low]<=v[high]) return low;
    return high;
}
long long int solve(int left, int right, int sz){
    int mid=findmin(left, right, 1, 1, sz);
    long long int answer=(query(right)-query(left-1))*v[mid];
    
    if(left<=mid-1) answer=max(answer, solve(left, mid-1 , sz));
    if(mid+1<=right) answer=max(answer, solve(mid+1, right, sz));
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    
    fw.resize(MX+2, 0);
    v.resize(n+2,0);
    for(int i=1;i<=n;++i) {
        cin>>v[i];
        fwUpdate(i, v[i]);
    }
    sg.resize(MX*4, 0);
    sgUpdate(1, n, 1);
    cout<<solve(1, n, n)<<'\n';
}
