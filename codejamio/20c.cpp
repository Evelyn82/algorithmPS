#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int INF=1e9;
const int MXS=101;

int d[2][2][2][2][MXS];
void init(){
    for(int i=0;i<MXS;++i){
        for(int k1=0;k1<2;++k1){
            for(int k2=0;k2<2;++k2){
                for(int k3=0;k3<2;++k3){
                    for(int k4=0;k4<2;++k4){
                        d[k1][k2][k3][k4][i]=-INF;
                    }
                }
            }
        }
    }
}
int main(){
    int t; cin>>t;
    for(int tc=1;tc<=t;++tc){
        string s; cin>>s;
        init();
        
        d[0][0][0][0][0]=0;
        for(int i=0;i<s.length();++i){
            for(int k1=0;k1<2;++k1){
                for(int k2=0;k2<2;++k2){
                    for(int k3=0;k3<2;++k3){
                        for(int k4=0;k4<2;++k4){
                            int ret=-INF;
                            if(s[i]=='I'){
                                if(k1==1) ret=max(ret, d[k1-1][k2][k3][k4][i]);
                                if(k2==1) ret=max(ret, d[k1][k2-1][k3][k4][i]);
                            }
                            else if(s[i]=='i'){
                                if(k3==1) ret=max(ret, d[k1][k2][k3-1][k4][i]);
                                if(k4==1) ret=max(ret, d[k1][k2][k3][k4-1][i]);
                            }
                            else if(s[i]=='O'){
                                if(k1==0) ret=max(ret, d[k1+1][k2][k3][k4][i]+1);
                                if(k3==0) ret=max(ret, d[k1][k2][k3+1][k4][i]);
                            }
                            else { // lowercase O
                                if(k2==0) ret=max(ret, d[k1][k2+1][k3][k4][i]);
                                if(k4==0) ret=max(ret, d[k1][k2][k3][k4+1][i]);
                            }
                            d[k1][k2][k3][k4][i+1]=ret;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<d[0][0][0][0][(int)s.length()]<<'\n';
    }
}
