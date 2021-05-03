#include <string>
#include <vector>

using namespace std;

int getLength(int n){
    string s= to_string(n);
    return s.size();
}
int solution(string s) {
    int answer = s.size();
    for(int cut=1;cut<=s.size()/2;++cut){
        int cnt=1, j=cut, prev=0;
        int ret=0;
        while(j+cut<=s.size()){
            int k;
            for(k=0;k<cut;++k){
                if(s[prev+k]!=s[j+k]) break;
            }
            if(k==cut) cnt++;
            else{
                if(cnt<2) ret+=cut;
                else ret+=(getLength(cnt)+cut);
                prev=j;
                cnt=1;
            }
            j+=cut;
        }
        ret+=s.size()-j;
        if(cnt>1) ret+=(getLength(cnt)+cut);
        else ret+=cut;
        
        
        answer=min(answer, ret);
    }
    return answer;
}
