#include <iostream>
#include <vector>
#include <string>
using namespace std;

int* getPi(string p){
    int sz=(int)p.size();
    int* pi=new int[sz];
    pi[0]=0;
    for(int i=1, j=0;i<sz;++i){
        while(p[i]!=p[j]){
            if(j==0){
                pi[i]=j; break;
            }j=pi[j-1];
        }
        if(p[i]==p[j]){
            pi[i]=++j;
        }
    }return pi;
}
vector<int> kmp(string t, string p, int* pi){
    int szT=(int)t.size(), szP=(int)p.size();
    vector<int> ret;
    
    for(int i=0, j=0;i<szT;++i){
        while(t[i]!=p[j]){
            if(j==0) break;
            j=pi[j-1];
        }
        if(t[i]==p[j]){
            if(++j==szP){
                ret.push_back(i-szP+2);
                j=pi[j-1];
            }
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string text, pattern;
    
    getline(cin, text);
    getline(cin, pattern);
    
    int* pi=getPi(pattern);
    vector<int> ret=kmp(text, pattern, pi);
    
    cout<<ret.size()<<'\n';
    for(vector<int>::size_type i=0;i<ret.size();++i) cout<<ret[i]<<' ';
}
