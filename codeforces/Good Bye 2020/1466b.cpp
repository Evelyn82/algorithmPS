#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
 
const int MAXN=1e5+1;
int arr[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int m;
        map<int,int> adj;
        for(int i=0;i<n;++i){
            cin>>m;
            adj[m]++;
        }
        
        int ret=0, prev=-1;
        map<int,int>::iterator it;
        it=adj.end(); it--;
        
        prev=it->first;
        if(it->second==1) {ret=1; prev++;}
        else ret=2;
        
        if(adj.size()>1){
            while(1){
                it--;
                if(prev-it->first>1){
                    prev=it->first;
                    if(it->second>1) ret+=2;
                    else {ret++; prev++;}
                }
                else{ ret++; prev=it->first;}
                
                if(it==adj.begin()) break;
            }
        }
        cout<<ret<<'\n';
    }
}
