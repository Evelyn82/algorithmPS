#include <cstdio>
#include <set>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    for(int tc=1;tc<=t;++tc){
        int n; scanf("%d", &n);
        
        int k=0, r=0, c=0, num;
        set<int> row[n], col[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d", &num);
                if(i==j) k+=num;
                row[i].insert(num);
                col[j].insert(num);
            }
        }
        
        for(int i=0;i<n;++i){
            if(row[i].size()!=n) r++;
            if(col[i].size()!=n) c++;
        }
        printf("Case #%d: %d %d %d\n", tc, k, r, c);
    }
}
