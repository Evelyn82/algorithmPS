#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    if(n%2){
        int a=n/2+1;
        cout<<(a*(a+1))*2<<'\n';
    }
    else cout<<pow((n/2)+1,2)<<'\n';
}
