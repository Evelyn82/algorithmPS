//
//  1457a.cpp
//  codeforces
//
//  Created by Evelyn 💚 on 2021/01/05.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        
        int ret=0;
        ret=max(ret, abs(r-1)+abs(c-1));
        ret=max(ret, abs(r-n)+abs(c-1));
        ret=max(ret, abs(r-1)+abs(c-m));
        ret=max(ret, abs(r-n)+abs(c-m));
        cout<<ret<<'\n';
    }
}
