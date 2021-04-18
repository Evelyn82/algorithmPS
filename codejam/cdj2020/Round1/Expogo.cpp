#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

string ret;
char isContrary(char c) {
    if (c == 'E') return 'W';
    if (c == 'W') return 'E';
    if (c == 'N') return 'S';
    if (c == 'S') return 'N';
}
void checkRet() {
    if (ret.size() <= 2) return;
    if (ret[1] == isContrary(ret[0])) {
        string tmp = "";
        tmp += ret[0];
        tmp += ret.substr(2);
        ret = tmp;
    }
}
bool solve(int x, int y, int digit){
    while(digit>-1){
        int d=(int)pow(2, digit);
        if(abs(x)>abs(y)){
            if(x>=0) {ret+='E'; x-=d;}
            else {ret+='W'; x+=d;}
        }
        else{
            if(y>=0) {ret+='N'; y-=d;}
            else {ret+='S'; y+=d;}
        }--digit;
    }
    if(x==0&&y==0) return true;
    return false;
}

/*
// recursion
bool solve(int x, int y, int digit) {
    if (digit == 0) {
        if (x == 0 && y == 1) { ret += 'N'; return true; }
        if (x == 0 && y == -1) { ret += 'S'; return true; }
        if (x == 1 && y == 0) { ret += 'E'; return true; }
        if (x == -1 && y == 0) { ret += 'W'; return true; }
        return false;
    }
    int ax = abs(x), ay = abs(y);
    if (ax > ay) {
        int d = (int)pow(2, digit);
        int next = (x >= 0) ? x - d : x + d;

        if (x > next) ret += 'E';
        else ret += 'W';
        return solve(next, y, digit - 1);
    }
    else {
        int d = (int)pow(2, digit);
        int next = (y >= 0) ? y - d : y + d;

        if (y > next) ret += 'N';
        else ret += 'S';
        return solve(x, next, digit - 1);
    }
}
*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, X, Y, ax, ay;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> X >> Y;

        ax = abs(X), ay = abs(Y);
        if (ax < ay) swap(ax, ay);
        double lg = log2(ax);
        lg = ceil(lg);

        ret = "";
        cout << "Case #" << tc << ": ";
        if (solve(X, Y, (int)lg)) {
            checkRet();
            reverse(ret.begin(), ret.end());
            cout << ret << '\n';
        }
        else cout << "IMPOSSIBLE\n";
    }
}
