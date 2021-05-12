#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;++i) cin>>v[i];
    sort(v.begin(), v.end());
    
   long long answer=0;
    for(int i=0;i<N-2;++i){
        if(v[i]>0) break;
        int low=i+1, high=N-1;
        while(low<high){
            int sum=v[i]+v[low]+v[high];
            if(sum==0){
                if(v[low]==v[high]){
                    answer+=(high-low+1)*(high-low)/2;
                    break;
                }
                int num=v[low], cnt1=0;
                while(v[low]==num) {
                    cnt1++; low++;
                }
                int cnt2=0;
                num=v[high];
                while(v[high]==num) {
                    cnt2++; high--;
                }
                answer+=cnt1*cnt2;
            }
            else if(sum>0) high--;
            else low++;
        }
    }cout<<answer<<'\n';
}
