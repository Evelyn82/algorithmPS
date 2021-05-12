#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll gcd, lcm; cin>>gcd>>lcm;
    ll tmp=lcm/gcd;
    
    ll i=sqrt(tmp), j;
    for(i;i>0;--i){
        if(tmp%i) continue;
        j=tmp/i;
        
        int cnt=0;
        for(int k=1;k<=i;++k){
            if(i%k==0 && j%k==0){
                if(++cnt>1) break;
            }
        }
        if(cnt==1){
            cout<<gcd*i<<' '<<gcd*j<<'\n';
            break;
        }
    }
}
