#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
const int MXN=55, MXK=33;

int arr[MXN][MXK], d[2][MXN*MXK];
int main(){
    int t; scanf("%d", &t);
    for(int tc=1;tc<=t;++tc){
        int n,k,p; scanf("%d %d %d", &n, &k, &p);
        memset(arr, 0, sizeof arr);
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=k;++j){
                scanf("%d", &arr[i][j]);
                arr[i][j]+=arr[i][j-1];
            }
        }
        memset(d, 0, sizeof d);
        int idx=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=k;++j){
                for(int b=p;b>=j;--b){
                    d[idx][b]=max(d[idx][b], d[idx^1][b]);
                    if(d[idx^1][b-j]+arr[i][j]>d[idx][b]) d[idx][b]= d[idx^1][b-j]+arr[i][j];
                }
            }idx=idx^1;
        }
        printf("Case #%d: %d\n", tc, d[idx^1][p]);
    }
}
