#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string , int> ump;
void combination(string s, string m, int sz, int idx){
    if(sz==0) {
        string menu=m;
        sort(menu.begin(), menu.end());
        ump[menu]++;
        return;
    }
    if(idx==s.size()) return;
    
    combination(s, m+s[idx], sz-1, idx+1);
    combination(s, m, sz, idx+1);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    string tmp="";
    for(int& i : course){
        for(string& s : orders){
            tmp="";
            combination(s, tmp, i, 0);
        }
    }
    int sz;
    vector<int> mxCnt(11,0);
    vector<vector<string>> candi(11);
    unordered_map<string, int>::iterator iter;
    for(iter=ump.begin();iter!=ump.end();++iter){
        sz=iter->first.size();
        if(iter->second>1 && mxCnt[sz]<=iter->second){
            if(mxCnt[sz]<iter->second) candi[sz].clear();
            candi[sz].push_back(iter->first);
            mxCnt[sz]=iter->second;
        }
    }
    vector<string> answer;
    for(int& i : course){
        for(string& s : candi[i]){
            answer.push_back(s);
        }
    }sort(answer.begin(), answer.end());
    return answer;
}
