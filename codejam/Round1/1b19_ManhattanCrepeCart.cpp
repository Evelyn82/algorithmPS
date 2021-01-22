//#include <bits stdc++.h>
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
#define MAXQ 100001

int P,Q;
int dx[MAXQ], dy[MAXQ];
int solve(int* arr){
    int ret=-1, cnt=0, mx=-98765421;
    for(int i=0;i<=Q;++i){
        cnt+=arr[i];
        if(mx<cnt){
            mx=cnt;
            ret=i;
        }
    }
    return ret;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int tc=1;tc<=t;++tc){
        memset(dx, 0, sizeof dx);
        memset(dy, 0, sizeof dy);
        scanf("%d%d",&P,&Q);
        int x, y; char c;
        for(int i=0;i<P;++i){
            scanf("%d%d %c", &x, &y, &c);
            if(c=='N') dy[y+1]++;
            else if(c=='S') dy[y]--;
            else if(c=='W') dx[x]--;
            else if(c=='E') dx[x+1]++;
        }
        printf("Case #%d: %d %d\n", tc, solve(dx), solve(dy));
    }
}
