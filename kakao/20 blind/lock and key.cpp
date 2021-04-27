#include <string>
#include <vector>

using namespace std;

int lockHall;
vector<vector<int>> lock2;
void turnKey(vector<vector<int>>& key){
    vector<vector<int>> ret=key;
    
    int sz=key.size();
    for(int j=0;j<sz;++j){
        for(int i=0;i<sz;++i){
            ret[j][sz-i-1]=key[i][j];
        }
    }key=ret;
}
int matchingCheck(int x, int y, const vector<vector<int>>& key){
    int y1=y, i, j, cnt=0;
    for(i=0;i<key.size();++i, ++x){
        for(j=0, y1=y;j<key.size();++j, ++y1){
            if(key[i][j] && lock2[x][y1]==1) return 0;
            if(key[i][j] && !lock2[x][y1]) cnt++;
        }
    }return cnt;
}
bool solved(const vector<vector<int>>& key){
    int lsz=lock2.size(), ksz=key.size();
    for(int i=0;i<=lsz-ksz;++i){
        for(int j=0;j<=lsz-ksz;++j){
            int d=matchingCheck(i, j, key);
            if(d==lockHall) return true;
        }
    }return false;
}
void setMargin(int keySz, const vector<vector<int>>& lock){
    int sz=2*keySz+(int)lock.size();
    lock2=vector<vector<int>>(sz, vector<int>(sz,-1));
    
    for(int i=0;i<lock.size();++i){
        for(int j=0;j<lock.size();++j){
            lock2[i+keySz][j+keySz]=lock[i][j];
            if(!lock[i][j]) lockHall++;
        }
    }
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    setMargin((int)key.size()-1, lock);
    
    for(int i=0;i<4;++i) {
        if(solved(key)) return true;
        turnKey(key);
    }
    return false;
}

