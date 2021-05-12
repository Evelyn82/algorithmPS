#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const long long DIV = (long long)1e9;
const int MAXN=4e4;
int N, M;
bool prime[MAXN+1];
vector<int> p;
map<int, int> ma, mb;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(prime, true, sizeof(prime));
    prime[1] = false;

    for (int i = 2; i * i <= MAXN; i++)
        if (prime[i])
            for (int j = i * i; j <= MAXN; j += i)
                prime[j] = false;

    for (int i = 2; i <= MAXN; i++)
        if (prime[i]) p.push_back(i);

    cin>>N;
    int x;
    for (int i = 1; i <= N; i++) {
        cin>>x;

        for (int j = 0; j < (int)p.size() && p[j] * p[j] <= x; j++)
            while (x % p[j] == 0)
                x /= p[j], ma[p[j]]++;
        
        if (x != 1) ma[x]++;
    }

    cin>>M;
    for (int i = 1; i <= M; i++) {
        cin>>x;

        for (int j = 0; j < (int)p.size() && p[j] * p[j] <= x; j++)
            while (x % p[j] == 0)
                x /= p[j], mb[p[j]]++;

        if (x != 1) mb[x]++;
    }

    long long ret = 1;
    bool flag = false;

    for (auto x : ma) {
        int cnt = min(x.second, mb[x.first]);

        while (cnt--) {
            if (flag)
                ret = (ret * x.first) % DIV;
            else
                ret = ret * x.first;

            if (ret >= DIV)
                ret = ret % DIV, flag = true;
        }
    }

    if (flag){
        ret%=DIV;
        cout.width(9);
        cout.fill('0');
        cout<<ret<<'\n';
        
        // printf("%09lld\n", res);
    }
    else cout<<ret<<'\n';
}
