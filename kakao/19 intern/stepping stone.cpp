#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0, low=0, high=200000000;
    while(low+1<high){
        int mid=(low+high)/2;
        
        int cnt=0, prev=-2;
        for(int i=0;i<stones.size();++i){
            if(stones[i]-mid<1) {
                if(prev==i-1) cnt++;
                else{
                    if(cnt>=k) break;
                    cnt=1;
                }prev=i;
            }
        }
        
        if (cnt>=k) high=mid;
        else {
            low=mid;
            answer=mid;
        }
    }
    return answer+1;
}
