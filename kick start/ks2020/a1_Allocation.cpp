#include <cstdio>
#include <algorithm>
using namespace std;
const int MXN=1e5+2;

int arr[MXN];
int main(){
    int t; scanf("%d", &t);
    for(int tc=1;tc<=t;++tc){
        int n,b; scanf("%d %d", &n ,&b);
        for(int i=0;i<n;++i) scanf("%d", &arr[i]);
        sort(arr, arr+n);
        
        int sum=0, i;
        for(i=0;i<n;++i){
            sum+=arr[i];
            if(sum>b) break;
        }printf("Case #%d: %d\n", tc, i);
    }
}
