#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
const ll MXF=1e5+1;
const ll MXN=2e4+1;
const ll INF=MXF*MXN;

ll dist[202][202];

ll solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i=0;i<=n;++i) {
        for(int j=0;j<=n;++j) {
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    for(vector<int>& v : fares){
        int from=v[0], to=v[1], cost=v[2];
        dist[from][to]=cost;
        dist[to][from]=cost;
    }

    // floyd warshall
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            if(i==k) continue;
            for(int j=1;j<=n;++j){
                if(i==j || k==j) continue;
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    ll answer = INF;
    for(int k=1;k<=n;++k){
        answer=min(answer, dist[s][k]+dist[k][a]+dist[k][b]);
    }
    return answer;
}
