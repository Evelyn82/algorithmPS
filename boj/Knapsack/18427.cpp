#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int d[1001];
vector<vector<int>> bcks;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N,M,H; cin>>N>>M>>H;
    
    // using getline
    cin.ignore();
    
    bcks.resize(N);
    for(int i=0;i<N;++i){
        string s;
        getline(cin, s);
        
        int num=0;
        for(int j=0;j<=s.size();++j) { 
            /*
            if(j==s.size()) bcks[i].push_back(num);
            else if(s[j]==' ') {
                bcks[i].push_back(num);
                num=0;
            }
            else num=(num*10)+(int)(s[j]-'0');
            */
            if(j==0 || s[j]==' ') bcks[i].push_back(stoi(&s[j]));
        }
    }
    
    d[0]=1; // initial setting
    
    for(int n=0;n<N;++n){
        vector<pair<int, int>> v;
        for(int h=0;h<=H;++h){
            for(int b=0;b<bcks[n].size();++b){
                if(d[h]!=0 && h+bcks[n][b]<=H){
                    v.push_back(make_pair(h+bcks[n][b], d[h]));
                }
            }
        }
        for(pair<int,int>& p : v){
            d[p.first]=(d[p.first]+p.second)%10007;
        }
    }
    cout<<d[H]<<'\n';
    return 0;
}
