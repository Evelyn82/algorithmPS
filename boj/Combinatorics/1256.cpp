#include <cstdio>
using namespace std;
const int INF=1e9;

int comb[201][201];
int main(){
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    
    comb[0][0]=1;
    for(int i=1;i<=n+m;++i){
        comb[i][0]=1;
        for(int j=1;j<i && j<=i;++j){
            comb[i][j]=comb[i-1][j-1] + comb[i-1][j];
            if(comb[i][j] > INF) comb[i][j]=INF;
        }
        if(i<=m) comb[i][i]=1;
    }
    k--;
    if(comb[n+m][m]<=k) {puts("-1"); return 0;}
    for(int i=m+n-1;i>=0;--i){
        if(i>=m && comb[i][m]>k) putchar('a');
        else{
            putchar('z');
            k -= comb[i][m];
            m--;
        }
    }putchar('\n');
}
