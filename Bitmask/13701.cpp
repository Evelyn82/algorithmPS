#include <cstdio>
#include <bitset>
using namespace std;

std::bitset<1<<25> bs;
int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        if(!bs[n]) printf("%d ", n);
        bs[n]=1;
    }
}
