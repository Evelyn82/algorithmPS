#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        // string 대신 char[]사용하면 memory reduced
        string s; cin>>s;
        
        int ans = 0, upp = 0, lwr = 0;
        for(char c : s){
            if(c == '(') lwr++;
            else if(c == '[') upp++;
            else if(c == ')'){
                if(lwr) {ans++; lwr--;}
            }
            else {
                if(upp) {ans++; upp--;}
            }
        }cout<<ans<<'\n';
    }
}
