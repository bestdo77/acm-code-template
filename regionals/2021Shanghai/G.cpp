#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=200050;
const int mod=998244353;
int Cn2[N];
int pre[N];
int fr[N];
vector <int> e[N];
int res=1;
int qpow (int a,int b){
    int res=1;
    for (;b;b >>= 1,a=a*a%mod){
        if (b&1)res=res*a%mod;
    }
    return res;
}
int DFS(int u,int fa){
   // cout <<u<<endl;
    int cnt = 0;
    for(int v : e[u]){
        if(v == fa) continue;
        cnt += DFS(v,u);
    }
  //  cout <<u<<" "<<cnt<<endl;
    if(cnt ==0) return 1;
    if(cnt&1){
        (res *= cnt)%=mod;
        for(int i = cnt-1;i>2;i-=2){
           ( res*=(i *(i-1)/2)%mod)%=mod;
        }
        (res *= qpow(fr[(cnt-1)/2],mod-2))%=mod;
     //   cout <<u<<" "<<res<<endl;
        return 0;
    }
    else{
        for(int i = cnt;i>2;i-=2){
            ( res*=(i *(i-1)/2)%mod)%=mod;
        }
        (res *= qpow(fr[cnt/2],mod-2))%=mod;
     //   cout <<u<<" "<<res<<endl;
        return 1;
    }
    
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin >>n;
    for (int i=1;i<=n;i++){
        Cn2[i]=(i*(i-1)/2)%mod;
    }
    fr[0]=1;
    fr[1]=1;
    for (int i=2;i<=n;i++){
        fr[i]=(fr[i-1]*i)%mod;
        //cout <<fr[i]<<" "<<qpow(fr[i],mod-2)<<endl;
    }
    for (int i=1;i<=n-1;i++){
        int u,v;
        cin >>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    DFS(1,0);
    cout <<res<<endl;
}