#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;

vector<long long> num, num2;
vector<char> sign, sign2;
long long calculate(){
    vector<char> v={'*','+','-'};
    long long answer=0;
    do{
        num2=num; sign2=sign;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<sign2.size();){
                if(v[i]!=sign2[j]) ++j;
                else{
                    if(v[i]=='+') num2[j]+=num2[j+1];
                    else if(v[i]=='-') num2[j]-=num2[j+1];
                    else num2[j]*=num2[j+1];
                    
                    sign2.erase(sign2.begin()+j);
                    num2.erase(num2.begin()+j+1);
                }
            }
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
    while(ss>>c>>n) {
        sign.push_back(c);
        num.push_back(n);
    }
}
long long solution(string expression) {
    splitted(expression);
    return calculate();
}
