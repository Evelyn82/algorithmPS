#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN=1e4+1;
bool isPrime[MAXN];

void setPrime(){
    fill(isPrime, isPrime+MAXN, true);
    isPrime[0]=isPrime[1]=false;
    int sqrtn=int(sqrt(MAXN));
    for(int i=2;i<=sqrtn;++i){
        if(isPrime[i]){
            for(int j=i*i;j<MAXN;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    setPrime();
    while(t--){
        int n; cin>>n;
        
        for(int i=n/2;i>1;--i){
            if(isPrime[i] && isPrime[n-i]){
                cout<<i<<' '<<n-i<<'\n';
                break;
            }
        }
    }
}
