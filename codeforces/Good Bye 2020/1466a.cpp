#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
 
int arr[51];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0;i<n;++i) cin>>arr[i];
        
        set<int> s;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                s.insert(abs(arr[i]-arr[j]));
            }
        }
        cout<<s.size()<<'\n';
    }
}
