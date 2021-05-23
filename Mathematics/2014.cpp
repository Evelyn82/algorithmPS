#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll=long long;

ll prime[100];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int K,N; cin>>K>>N;
    priority_queue<ll> pq;
    for(int i=0;i<K;++i) {
        cin>>prime[i];
        pq.push(-prime[i]);
    }
    
    for(int i=0;i<N-1;++i){
        ll now=-pq.top();
        pq.pop();
        
        for(int j=0;j<K;++j){
            ll num=now*prime[j];
            pq.push(-num);
            
            if(now % prime[j] == 0) break;
        }
    }
    cout<<-pq.top()<<'\n';
}

// using set
// 280ms
/*
ll prime[100];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int K,N; cin>>K>>N;
    
    set<ll> s;
    priority_queue<ll> pq;
    ll mx=0;
    for(int i=0;i<K;++i) {
        cin>>prime[i];
        s.insert(prime[i]);
        pq.push(-prime[i]);
        mx=max(mx, prime[i]);
    }
    
    for(int i=0;i<N-1;++i){
        ll now=-pq.top();
        pq.pop();
        
        
        for(int j=0;j<K;++j){
            ll num=now*prime[j];
            
            if(pq.size() > N-i && num>=mx) continue;
            
            if(s.find(num)==s.end()){
                pq.push(-num);
                s.insert(num);
                mx=max(mx, num);
            }
        }
    }
    cout<<-pq.top()<<'\n';
}

*/
