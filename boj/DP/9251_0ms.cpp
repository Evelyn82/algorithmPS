#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN=1e3+1;
int d[2][MAXN];
char a[MAXN], b[MAXN];
int main(){
    scanf("%s %s", a+1, b+1);
    
    int j, idx=0;
    for(int i=1;a[i];++i){
        for(j=1;b[j];++j){
            if(a[i]==b[j]) d[idx][j]=d[idx^1][j-1]+1;  // 더 정확히는 d[idx][j]=max(d[idx][j], d[idx^1][j-1]+1); 순서대로 누적되니깐 상관없다..?
            else d[idx][j]=max(d[idx][j-1], d[idx^1][j]);
        }
        idx^=1;
    }
    printf("%d\n", d[idx^1][j-1]);
}
