#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using pss=pair<string, string>;

pss splitted(string s){
    int open=0, close=0, i;
    for(i=0;i<s.size();++i){
        if(s[i]=='(') open++;
        else close++;
        if(open==close) break;
    }
    return make_pair(s.substr(0, i+1), s.substr(i+1));
}
bool checkParenthesis(string s){
    int open=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='(') open++;
        else {
            if(--open<0) return false;
        }
    }return true;
}
string step1234(string p){
    if(p.size()==0) return p;
    
    pss s=splitted(p);
    if(checkParenthesis(s.first)){
        return s.first+step1234(s.second);
    }
    else{
        string s2="(";
        s2+=step1234(s.second);
        s2+=")";
        for(int i=1;i<s.first.size()-1;++i){
            if(s.first[i]=='(') s2+=")";
            else s2+="(";
        }return s2;
    }
}
string solution(string p) {
    return step1234(p);
}
