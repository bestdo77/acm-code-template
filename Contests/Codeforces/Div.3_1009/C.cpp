#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
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
map<int,int> vis;
void Atomatic_AC_machine(){
    int x;cin>>x;
    if(vis[x]){
        cout<<-1<<endl;
    }else{
        bool flag1=1,flag2=1;
        int y=x;
        for(int j=30;j>=0;j--){
            if(flag1){
                if((1ll<<j)&x){
                    y^=(1ll<<j);
                    flag1=0;
                }
            }else{
                if(flag2){
                    if(!((1ll<<j)&x)){
                        y^=(1ll<<j);
                        flag2=0;
                    }
                }
            }
        }
        cout<<y<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    int x=1;
    while(x<=3e9){
        vis[x]=1;
        vis[x-1]=1;
        x*=2;
    }
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}