#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        
        if(s.length()%2|| s[0]==')' || s[s.size()-1]=='(') cout<<"NO\n";
        else cout<<"YES\n";
    }
}
