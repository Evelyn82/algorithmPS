#include <queue>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

vector<vector<int>> graph, tree;
vector<bool> vst, nowvst;
void makeTree(){
    queue<int> q;
    q.push(0);
    vst[0]=true;
    
    while(!q.empty()){
        int now=q.front(); q.pop();
        for(int i=0;i<graph[now].size();++i){
            int nxt=graph[now][i];
            if(!vst[nxt]){
                tree[now].push_back(nxt);
                q.push(nxt);
                vst[now]=true;
            }
        }
    }
}
bool findCycle(int n){
    nowvst[n]=true;
    vst[n]=true;
    
    for(int i=0;i<tree[n].size();++i){
        int nxt=tree[n][i];
        if(!vst[nxt]){
            if(findCycle(nxt)) return true;
        }
        if(nowvst[nxt]) return true;
    }
    nowvst[n]=false;
    return false;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    graph.resize(n);
    tree.resize(n);
    
    int from, to;
    for(vector<int>& v : path){
        from=v[0]; to=v[1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vst.resize(n, false);
    makeTree();
    
    for(vector<int>& v : order){
        if(v[1]==0) return false;
        tree[v[0]].push_back(v[1]);
    }
    
    for(int i=0;i<n;++i) vst[i]=false;
    nowvst.resize(n, false);
    return !findCycle(0);
}
