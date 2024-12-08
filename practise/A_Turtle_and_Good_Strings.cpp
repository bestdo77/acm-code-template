#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<i64, i64>
#define endl '\n'
const i64 N=1e6+10;
const i64 N1=1e3+10;
const i64 mod=1e9+7;
const i64 element=3;
vector<i64> G[N];
void Atomatic_AC_machine(){
     i64 ans=0,min=inf;
     i64 n,m;cin>>n>>m;
     for(i64 i=1;i<=n;i++){
        i64 len=0;cin>>len;
        vector<i64> a;
        a.push_back(0);
        for(i64 j=1;j<=len;j++){
            i64 x;cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        for(i64 j=0;j<=len;j++){
            cout<<a[j]<<" ";
        }cout<<endl;
        i64 kon=0;
        for(i64 j=1;j<=len;j++){
            if(a[j]-a[j-1]==2) kon++;
            else if(a[j]==a[j-1]||a[j]-a[j-1]==1) continue;
            else{
                kon=2;
                ans=max(a[j-1]+2,ans);
                break;
            }
            if(kon==2){
                ans=max(a[j-1]+1,ans);
                break;
            }
        }
        if(kon==1) ans=max(a[len]+1,ans);
        else if(kon==0) ans=max(a[len]+1,ans);
        // cout<<ans<<endl;
     }
    //  cout<<ans<<endl;
     if(m>ans){
        cout<<(ans+1)*ans+(m+ans+1)*(m-ans)/2<<endl;
     }else{
        cout<<(m+1)*ans<<endl;
     }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    i64 t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}