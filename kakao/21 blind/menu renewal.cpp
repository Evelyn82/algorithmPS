#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

bool d[20][32];
set<string> st;
vector<string> solution(vector<string> orders, vector<int> course) {
   for(int i=0;i<orders.size();++i){
        for(char& c : orders[i]){
            d[i][c-'A']=true;
        }
    }
    
    vector<bool> cou(11, false);
    for(int& i : course) cou[i]=true;
    
    map<string, int> candi[11];
    for(int i=0;i<orders.size();++i){
        string s="";
        for(int j=i+1;j<orders.size();++j){
            s="";
            for(int k=0;k<32;++k){
                if(d[i][k] && d[j][k]){
                    s+=(k+65);
                    if(s.size()>1 && cou[s.size()]) candi[s.size()][s]++;
                }
            }
        }
    }
    
    vector<vector<pair<int,string>>> tmpAns(11);
    map<string, int>::iterator iter;
    for(int& i : course){
        for(iter=candi[i].begin();iter!=candi[i].end();++iter){
            if(tmpAns[i].empty()) tmpAns[i].push_back(make_pair(iter->second,iter->first));
            else {
                if(tmpAns[i].back().first<=iter->second) {
                while(!tmpAns[i].empty() && tmpAns[i].back().first<iter->second)tmpAns[i].pop_back();
                tmpAns[i].push_back(make_pair(iter->second, iter->first));
                }
            }
        }
    }
    vector<string> ans;
    for(int& i : course) {
        for(pair<int, string>& j : tmpAns[i]) ans.push_back(j.second);
    }sort(ans.begin(), ans.end());
    return ans;
}
