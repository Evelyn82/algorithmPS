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
    // a로 전달시 WA -> line8 if(b==1) return a%c;로 작성시 a자체를 전달해도 AC
    cout<<solve(a%c,b,c)<<'\n';
}
