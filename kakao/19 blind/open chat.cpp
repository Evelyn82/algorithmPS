#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, string> mp;
vector<string> solution(vector<string> record) {
    string menu, id, nickname;
    for(string& s : record){
        stringstream ss(s);
        ss>>menu>>id>>nickname;
        if(menu=="Enter" || menu=="Change") mp[id]=nickname;
    }
    
    vector<string> answer;
    for(string& s : record){
        stringstream ss(s);
        ss>>menu>>id>>nickname;
        if(menu=="Enter") answer.push_back(mp[id]+"님이 들어왔습니다.");
        else if(menu=="Leave") answer.push_back(mp[id]+"님이 나갔습니다.");
    }
    return answer;
}
