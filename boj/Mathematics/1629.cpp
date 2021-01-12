#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll solve(int a, int b, int c){
    if(b==1) return a;
    ll tmp=solve(a,b/2,c);
    
    if(b%2) return ((tmp*tmp)%c)*a%c;
    else return (tmp*tmp)%c;
}
int main(){
    int a,b,c; cin>>a>>b>>c;
    // a로 전달시 WA
    cout<<solve(a%c,b,c)<<'\n';
}
