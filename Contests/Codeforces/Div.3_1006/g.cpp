#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int pre[N];
int cal(int x,int base){
    vector<int> st;
    while(x){
        st.push_back(x%base);
        x/=base;
    }
    int ans=0;
    for(auto x:st){
        ans=(ans*base)%mod;
        ans+=x;
    }
    return ans%mod;
}
void Atomatic_AC_machine(){
    // db((int)(pow(2,8)))
    // cendl
    int n,k;cin>>n>>k;
    int ans=0;
    if(k>n){
        ans=((k-n)%mod*n)%mod;
        k=n;
    }
    int lim=min((int)sqrt(n),k);
    for(int i=2;i<=lim;i++){
        ans=(ans+cal(n,i))%mod;
    }
    for(int l=lim+1,r;l<=k;l=r+1){
        int x=n/l;
        r=min(k,n/x);
        ans=(ans+(((l+r))*(r-l+1)/2)%mod*n)%mod;
        ans=(ans+((pre[r]-pre[l-1]+mod)%mod*x)%mod)%mod;
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    for(int i=1;i<=300000;i++){
        pre[i]=((pre[i-1]+(1-i*i))%mod+mod)%mod;
    }
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}