#include <bits/stdc++.h>
using namespace std;
#define int  long long
using pii = pair<int,int>;
const int infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;

#define endl '\n'
#define all(x) x.begin(),x.end()

#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif


const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
bitset<N> bs;
void sieve(){
    bs.set();
    bs[1]=0;
    for(int i=2;i<=2e5;i++){
        if(!bs[i]) continue;
        for(int j=2*i;j<=2e5;j+=i){
            bs[j]=0;
        }
    }
} 
void Atomatic_AC_machine(){
    int n;cin>>n;
    int sum=0;
    vector<int> has,vis(n+1,0);
    int prime=2;
    for(int i=1;i<=n;i++){
        if(bs[i]&&abs(n/2-prime)>abs(i-n/2)){
            prime=i;
        }
    }
    db(prime)
    cendl
    for(int i=n;i>=1;i--){
        if(vis[i]){
            continue;
        }else{
            if(2*prime-i>=1&&2*prime-i<=n&&!vis[2*prime-i]){
                has.push_back(2*prime-i);
                vis[2*prime-i]=1;
            }
            if(!vis[i]){
                vis[i]=1;
                has.push_back(i);
            }
        }
    }
    reverse(has.begin(),has.end());
    for(auto x:has){
        cout<<x<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    sieve();
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}