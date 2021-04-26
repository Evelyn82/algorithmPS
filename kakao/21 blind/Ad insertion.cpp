#include <string>
#include <vector>
#include <sstream>
using namespace std;
using pii=pair<int,int>;
const int MX=100*60*60;

int chgTime(string str){
    stringstream ss(str);
    int h, m, s; char skip;
    ss>>h>>skip>>m>>skip>>s;
    return s+(m*60)+(h*3600);
}
string timeToString(int n){
    string ret="";
    int t=n/3600;
    n%=3600;
    if(t<10) ret+='0';
    ret+=to_string(t);
    ret+=":";
    
    t=n/60;
    n%=60;
    if(t<10) ret+='0';
    ret+=to_string(t);
    ret+=":";
    
    if(n<10) ret+='0';
    ret+=to_string(n);
    return ret;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    int playtime=chgTime(play_time);
    vector<int> time(playtime+1, 0);
    
    for(string& s : logs){
        int start=chgTime(s.substr(0, 8));
        int finish=chgTime(s.substr(9));
        for(;start<finish;++start) time[start]++;
    }
    
    int advtime=chgTime(adv_time);
    int finalAdvTime=0, i;
    long long sum=0, tmpSum=0;
    for(i=0;i<advtime;++i) sum+=time[i];
    
    tmpSum=sum;
    for(;i<playtime;++i){
        tmpSum+=time[i];
        tmpSum-=time[i-advtime];
        if(sum<tmpSum){
            finalAdvTime=i-advtime+1;
            sum=tmpSum;
        }
    }
    string answer = timeToString(finalAdvTime);
    return answer;
}
