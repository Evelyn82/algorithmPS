#include <string>
#include <vector>
#include <cmath>
#define mp make_pair
using namespace std;
using pii=pair<int, int>;

vector<pii> v(10);
pii left, right;
string dist(int n, string hand){
    int leftDist=abs(left.first-v[n].first)+ abs(left.second-v[n].second);
    int rightDist=abs(right.first-v[n].first)+abs(right.second-v[n].second);
    
    if(leftDist<rightDist) return "L";
    if(leftDist==rightDist) return hand;
    return "R";
}
string chooseFinger(int n, string hand){
    if(n!=0 && n%3==0) return "R";
    if(n==0 || n==2 || n==5 || n==8) return dist(n, hand);
    return "L";
}
string solution(vector<int> numbers, string hand) {
    v[0]=mp(3, 1);
    int idx=0;
    for(int i=0;i<3;++i) for(int j=0;j<3;++j) v[++idx]=mp(i, j);
    
    left=mp(3, 0); right=mp(3, 2);
    
    string answer = "";
    hand=(hand=="left")?"L":"R";
    
    for(int& i : numbers){
        string s=chooseFinger(i, hand);
        answer+=s;
        if(s=="L") left=v[i];
        else right=v[i];
    }
    return answer;
}
