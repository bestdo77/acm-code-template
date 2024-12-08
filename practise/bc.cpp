#include <iostream>
using namespace std;
int codd(int x){ return x/2+x%2; }
int main(){
    int t;cin>>t;
    while(t--){
        bool flag=0;
        int l,r,k;cin>>l>>r>>k;
        if(codd(r)-codd(l-1)<=k) flag=1;
        if(l==r){
            flag=(l==1)?0:1;
        } 
        cout<<(flag?"YES":"NO")<<endl;
    }
}