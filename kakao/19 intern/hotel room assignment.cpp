#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll=long long;
map<ll,ll> mp;

ll findRoom(ll n){
    if(mp.find(n)==mp.end()) return n;
    return mp[n]=findRoom(mp[n]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(ll& i : room_number){
        ll room=findRoom(i);
        answer.push_back(room);
        mp[room]=room+1;
    }
    return answer;
}
