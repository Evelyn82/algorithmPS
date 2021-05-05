#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
using ll=long long;
unordered_map<ll,ll> ump;

ll findRoom(ll n){
    if(ump.find(n)==ump.end()) return n;
    return ump[n]=findRoom(ump[n]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(ll& i : room_number){
        ll room=findRoom(i);
        answer.push_back(room);
        ump[room]=room+1;
    }
    return answer;
}
