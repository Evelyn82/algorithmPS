#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN=123456*2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    bool num[MAXN+1]={1,1};
    int prime[12387]={};
    int idx=0;
    for(int i=2;i<=MAXN;i++){
        if(!num[i]){
            prime[idx++]=i;
            for(ll j=(ll)i*i;j<=MAXN;j+=i)
                num[j]=true;
        }
    }
    
    int n;
    while(cin>>n){
        if(n==0) break;
        printf("%ld\n",lower_bound(prime,prime+idx,2*n+1)-upper_bound(prime,prime+idx,n));
    }
}

