#include <iostream>
using namespace std;
typedef long long ll;

int divide(int n, int d){
    int ret=0;
    while(1){
        if(n%d) return ret;
        n/=d;
        ret++;
    }
}
int main(){
    ll n; cin>>n;
    
    ll five=0;
    /*
    for(int i=1;i<=n;++i){
        five+=divide(i, 5);
        
        // div 5만 해도 되는 이유 -> 소인수 2의 개수가 5보다 훨씬 많아서 고려 안 해도 된다.
        //two+=divide(i,2);
    }
    */
    
    // 25(5^2), 125(5^3), 625(5^4)... 5의 거듭제곱부분에서 +1씩 해주는 방법
    for(int i=5;i<=n;i*=5){
        five+=n/i;
    }
    cout<<five<<'\n';
}
