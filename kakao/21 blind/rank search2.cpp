#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
map<string, int> mp;
struct Node{
    int n;
    Node* child[3];
    vector<int> score;

    Node(bool isRoot) {
        n=(isRoot?3:2);
        for(int i=0;i<3;++i) child[i]=NULL;
        score.clear();
    }
    void insert(const vector<int>& v, int idx){
        if(idx==4){
            score.push_back(v[idx]);
            return;
        }
        int div=(idx>0)?2:3;
        int now=v[idx] % div;
        if(!child[now]) child[now]=new Node(false);
        child[now]->insert(v, idx+1);
    }
    int query(const vector<int>& v, int idx){
        if(idx==4){
            auto cnt=lower_bound(score.begin(), score.end(), v[idx])-score.begin();
            return (int)score.size()-cnt;
        }

        int ret=0;
        if(v[idx]==10){
            for(int i=0;i<n;++i){
                if(child[i])ret+=child[i]->query(v, idx+1);
            }
        }
        else{
            int div=(idx>0?2:3);
            int nxt=v[idx]%div;
            if(child[nxt])ret+=child[nxt]->query(v, idx+1);
        }
        return ret;
    }
    void sorted(int depth){
        if(depth==4){
            sort(score.begin(), score.end());
            return;
        }
        for(int i=0;i<n;++i){
            if(child[i])child[i]->sorted(depth+1);
        }
    }
};
vector<int> solution(vector<string> info, vector<string> query) {
    // map init
    mp["cpp"]=0;
    mp["java"]=1;
    mp["python"]=2;
    mp["backend"]=4;
    mp["frontend"]=5;
    mp["junior"]=6;
    mp["senior"]=7;
    mp["chicken"]=8;
    mp["pizza"]=9;
    mp["-"]=10;


    Node* root=new Node(true);
    string token;
    // insert
    for(string& s : info){
        stringstream ss(s);
        vector<int> v;
        for(int i=0;i<4;++i) {
            ss>>token;
            int num=mp[token];
            v.push_back(num);
        }
        ss>>token;
        v.push_back(stoi(token));
        root->insert(v,0);
    }root->sorted(0);

    vector<int> answer;
    for(string& s : query){
        stringstream ss(s);
        vector<int> v;

        for(int i=0;i<4;++i){
            ss>>token;
            v.push_back(mp[token]);
            ss>>token;
            if(i==3) v.push_back(stoi(token));
        }
        answer.push_back(root->query(v, 0));
    }
    return answer;
}
