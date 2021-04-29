#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;

vector<int> d[3][2][2][2];
map<string, int> mp;
void initSet(){
    int i=0;
    mp["cpp"]=i; mp["java"]=++i; mp["python"]=++i;
    mp["backend"]=++i; mp["frontend"]=++i;
    mp["junior"]=++i; mp["senior"]=++i;
    mp["chicken"]=++i; mp["pizza"]=++i;
}
int findApplicant(vector<int> v, int idx, int score){
    if(idx==v.size()){
        int l=v[0], j=v[1], c=v[2], f=v[3];
        int cnt=lower_bound(d[l][j][c][f].begin(), d[l][j][c][f].end(), score)-d[l][j][c][f].begin();
        return d[l][j][c][f].size()-cnt;
    }
   
    int d=v[idx];
    if(d!=-1) return findApplicant(v, idx+1, score);
    else{
        int sum=0;
        d=(idx==0?3:2);
        vector<int> v2=v;
        for(int i=0;i<d;++i){
            v2[idx]=i;
            sum+=findApplicant(v2,idx+1, score);
        }return sum;
    }
}
void sorted(vector<int> v, int idx){
    if(idx==4){
        sort(d[v[0]][v[1]][v[2]][v[3]].begin(), d[v[0]][v[1]][v[2]][v[3]].end());
        return;
    }
    
    int sz=2;
    if(idx==0) sz=3;
    vector<int> v2=v;
    for(int i=0;i<sz;++i){
        v2[idx]=i;
        sorted(v2, idx+1);
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    initSet();
    string lang, job, career, food; int score;
    for(string& s : info){
        stringstream ss(s);
        ss>>lang>>job>>career>>food>>score;
        d[mp[lang]][mp[job]-3][mp[career]-5][mp[food]-7].push_back(score);
    }
    vector<int> order;
    for(int i=0;i<4;++i) order.push_back(0);
    sorted(order,0);
    
    string skip;
    vector<int>  answer;
    order.clear();
    for(string& s : query){
        stringstream ss(s);
        ss>>lang>>skip>>job>>skip>>career>>skip>>food>>score;
        
        order.clear();
        order.push_back((lang=="-")?-1:mp[lang]);
        order.push_back((job=="-")?-1:mp[job]-3);
        order.push_back((career=="-")?-1:mp[career]-5);
        order.push_back((food=="-")?-1:mp[food]-7);
        answer.push_back(findApplicant(order,0, score));
    }
    return answer;
}
