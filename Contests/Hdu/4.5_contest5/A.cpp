#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=998244353;
i64 n,m;
vector<i64> merge(vector<i64> a,vector<i64> b){
    vector<i64> re(m,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            re[(i+j)%m]=(re[(i+j)%m]+a[i]*b[j])%mod;   
        }
    }
    return re;
}
vector<i64> mul(vector<i64> x,i64 cnt){
    vector<i64> re(m,0);
    re[0]=1;
    while(cnt){
        if(cnt%2) re=merge(re,x);
        x=merge(x,x),cnt/=2;
    }
    return re;
}
void Atomatic_AC_machine(){
    cin>>n>>m;
    vector<i64> cnt(m,0);
    for(int i=0;i<m;i++){
        cnt[i]=n/m;
        if(i<=n%m&&i!=0) cnt[i]++;
    }
    vector<i64> ans(m,0);
    ans[0]=1;
    for(int i=0;i<m;i++){
        vector<i64> x(m,0);
        x[0]++;
        x[i]++;
        ans=merge(ans,mul(x,cnt[i]));
    }
    cout<<(ans[0]-1+mod)%mod<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}