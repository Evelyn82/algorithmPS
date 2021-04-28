#include <string>
#include <vector>
#define mp make_pair
using namespace std;
vector<vector<pair<int, bool>>> adj;

vector<bool> vst, nowPath;
void oneWay(int n){
    vst[n]=true;
    for(pair<int, bool>& next : adj[n]){
        if(vst[next.first]) next.second=false;
        else oneWay(next.first);
    }
}
bool isCycle(int n){
    vst[n]=true;
    nowPath[n]=true;
    for(pair<int, bool>& next : adj[n]){
        if(!next.second) continue;
        if(!vst[next.first]) {
            if(isCycle(next.first)) return true;
        }
        if(nowPath[next.first]) return true;
    }
    nowPath[n]=false;
    return false;
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    adj.resize(n);
    for(vector<int>& v:path){
        int from=v[0], to=v[1];
        adj[from].push_back(mp(to, true));
        adj[to].push_back(mp(from, true));
    }
    vst.resize(n, false);
    oneWay(0);
    
    for(vector<int>& v:order) adj[v[0]].push_back(mp(v[1], true));
    
    for(int i=0;i<vst.size();++i) vst[i]=false;
    nowPath.resize(n, false);
    return !isCycle(0);
}
