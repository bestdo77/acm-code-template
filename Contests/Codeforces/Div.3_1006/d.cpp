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
const int N1=3e3+10;
const int mod=1e9+7;
int a[N];
int premx[N1][N1];//前i个数字中，大于第j个数字的有几个
int premn[N1][N1];
void Atomatic_AC_machine(){
    int l=1,r=1,mx=0;
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            premx[i][j]=premn[i][j]=0;
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            premx[i][j]=premx[i-1][j]+(a[i]>a[j]?1:0);
            premn[i][j]=premn[i-1][j]+(a[i]<a[j]?1:0);
        }
    }
    pa(&premx[0][0],n,n);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int ans=0;
            ans-=(premx[j][i]-premx[i][i]);
            ans+=(premn[j][i]-premn[i][i]);
            if(ans>mx){
                mx=ans;
                l=i,r=j;
            }
        }
    }
    cout<<l<<" "<<r<<endl;
    
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