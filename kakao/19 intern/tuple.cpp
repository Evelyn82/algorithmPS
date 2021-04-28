#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

vector<int> v[501];
set<int> st;

vector<int> solution(string s) {
    stringstream ss(s);
    char skip; int num;
    vector<int> input;
    ss>>skip;
    while(ss>>skip){
        while(ss>>num>>skip){
            input.push_back(num);
            st.insert(num);
            if(skip=='}'){
                v[input.size()]=input;
                input.clear();
                ss>>skip;
                break;
            }
        }if(skip=='}') break;
    }
    
    int i=0;
    vector<int> answer;
    while(v[++i].size()){
        for(int& j : v[i]){
            if(st.find(j)!=st.end()) {
                answer.push_back(j);
                st.erase(st.find(j));
                break;
            }
        }
    }
    return answer;
}
