#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(),dist.end());
    int ans=dist.size()+1, wsz=(int)weak.size();
    
    weak.resize(wsz*2);
    for(int i=wsz;i<weak.size();++i) weak[i]=weak[i-wsz]+n;
    
    do{
        for(int w=0;w<wsz;++w){
            int start=weak[w], finish=weak[w+wsz-1];
            for(int d=0;d<dist.size();++d){
                start+=dist[d];
                if(start>=finish){
                    ans=min(ans, d+1);
                    break;
                }
                int nxt=upper_bound(weak.begin(), weak.end(), start)-weak.begin();
                start=weak[nxt];
            }
        }
    }while(next_permutation(dist.begin(), dist.end()));

    if(ans==dist.size()+1) return -1;
    return ans;
}
