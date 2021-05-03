#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

vector<long long> num;
vector<char> sign;
long long findAbsNum(){
    long long answer=0;
    vector<char> v={'*','+','-'};
    
    vector<char> sign2, nextSign;
    vector<long long> num2, nextNum;
    
    do{
        num2=num;
        sign2=sign;
        for(int i=0;i<3;++i){
            nextSign.clear(); nextNum.clear();
            nextNum.push_back(num2[0]);
            for(int j=0;j<sign2.size();j++){
                if(v[i]!=sign2[j]){
                    nextSign.push_back(sign2[j]);
                    nextNum.push_back(num2[j+1]);
                }
                else{
                    if(v[i]=='+') nextNum[nextNum.size()-1]=nextNum.back()+num2[j+1];
                    else if(v[i]=='-') nextNum[nextNum.size()-1]=nextNum.back()-num2[j+1];
                    else nextNum[nextNum.size()-1]=nextNum.back()*num2[j+1];
                }
            }
            num2.clear(); num2=nextNum;
            sign2.clear(); sign2=nextSign;
        }
        if(abs(num2[0])>answer) answer=abs(num2[0]);
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}
void splitted(string expression){
stringstream ss(expression);
    long long n; char c;
    ss>>n;
    num.push_back(n);
    while(ss>>c>>n){
        sign.push_back(c);
        num.push_back(n);
    }
    
}
long long solution(string expression) {
    splitted(expression);
    return findAbsNum();
}
