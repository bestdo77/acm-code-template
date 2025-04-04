#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
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
#define tii tuple<int,int,int>
queue<tii> q;
bool flag=0;
void query(int i,int j,int k){
    int idx;
    cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
    cin>>idx;
    if(idx==0){
        flag=1;
        cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
        return;
    }
    q.push({i,j,idx});
    q.push({i,k,idx});
    q.push({j,k,idx});
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    while(q.size()){
        q.pop();
    }
    q.push({1,2,3});
    flag=0;
    while(!flag){
        auto [i,j,k]=q.front();
        q.pop();
        query(i,j,k);
    }
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}