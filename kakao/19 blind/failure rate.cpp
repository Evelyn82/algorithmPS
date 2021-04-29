#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end());
    
    double user=(int)stages.size()*1.0;
    vector<pair<double,int>> failureRate;
    for(int i=1;i<=N;++i){
        int cnt=upper_bound(stages.begin(), stages.end(), i)-lower_bound(stages.begin(), stages.end(), i);
        if(cnt<1) failureRate.push_back(make_pair(0, i));
        else{
            failureRate.push_back(make_pair((double)cnt/user, i));
            user-=cnt;
        }
    }
    sort(failureRate.begin(), failureRate.end(), [&](const pair<double, int>& a, const pair<double, int>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
});
    vector<int> answer;
    for(pair<double, int>& f : failureRate){
        answer.push_back(f.second);
    }
    return answer;
}
