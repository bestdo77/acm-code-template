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

void Atomatic_AC_machine(){
    int n,x,k;cin>>n>>x>>k;
    string s;cin>>s;
    int time1=0,time2=0;
    bool flag1=0,flag2=0;
    for(auto it:s){
        if(it=='L'){
            x--;
        }else{
            x++;
        }
        time1++;
        if(x==0){
            flag1=1;
            break;
        }
    }
    int p=0;
    for(auto it:s){
        if(it=='L'){
            p--;
        }else{
            p++;
        }
        time2++;
        if(p==0&&time2!=1){
            flag2=1;
            break;
        }
    }
    // db(time1<<" "<<time2<<" "<<flag1<<" "<<flag2)
    // cendl
    if(!flag1){
        cout<<0<<endl;
    }else{
        if(flag2){
            int ans=0;
            if(k>=time1){
                k-=time1;
                ans=1+k/time2;
            }
            cout<<ans<<endl;
        }else{
            int ans=0;
            if(k>=time1){
                ans=1;
            }
            cout<<ans<<endl;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}