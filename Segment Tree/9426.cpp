#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MX=65536;
vector<int> fw;

void add(int idx, int diff){
    while(idx <= fw.size()){
        fw[idx]+=diff;
        idx += (idx & -idx);
    }
}
int findMedian(int idx){
    int cnt=0;
    while(idx){
        cnt+=fw[idx];
        idx -= (idx & -idx);
    }return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,k; cin>>n>>k;
    fw.resize(MX+1, 0);
    
    queue<int>q;
    int num, target=(k+1)/2;
    long long answer=0;
    for(int i=0;i<n;++i){
        cin>>num;
        add(num+1, 1);
        q.push(num);
        
        if(i>=k-1){
            int low=1, high=MX, mid, cnt, idx;
            while(low<=high){
                mid=(low+high)/2;
                if(findMedian(mid)>=target){
                    idx=mid;
                    high=mid-1;
                }else low=mid+1;
            }
            answer+=idx-1;
            add(q.front()+1, -1);
            q.pop();
        }
    }
    cout<<answer<<'\n';
}
