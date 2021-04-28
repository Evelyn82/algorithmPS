#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> jewelry(gems.begin(), gems.end());

    int low=0, high=0;
    unordered_map<string, int> ump;
    for(string& s : gems){
        ump[s]++;
        if(jewelry.size()==ump.size()) break;
        high++;
    }

    vector<int> answer(2);
    int mn=high-low;
    answer[0]=low+1;
    answer[1]=high+1;
    while(high<gems.size()){
        string key=gems[low];
        ump[key]--; low++;

        if(ump[key]==0){
            high++;
            for(;high<gems.size();++high){
                ump[gems[high]]++;
                if(key==gems[high]) break;
            }
        }
        if(mn>high-low){
            answer[0]=low+1;
            answer[1]=high+1;
            mn=high-low;
        }
    }
    return answer;
 }
