#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
#define int long long
#define pii pair <int,int>
#define ld long double
#define endl "\n"
const int N=200050;
int a[N];
int b[N],v[N];
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >>n;
        for (int i=1;i<=n;i++)cin >>a[i];
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++) v[i]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(!v[i]||i==j) continue;
                if(a[i]%a[j]==0) v[i]=0;
            }
        }
        int cntt=0;
        for(int i=1;i<=n;i++){
            if(v[i]) cntt++;
        }
        bool flag=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]%a[j]==1){
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            sort(a+1,a+1+n);
            int gcdd=a[1];
            for(int i=1;i<=n;i++){
                gcdd=__gcd(gcdd,a[i]);
            }
            if(a[1]==gcdd) flag=0;
        }
        int ans=0;
        if(flag) ans=n+1;
        else ans=n;
        if(cntt==1) cout<<n-1<<endl;
        else if(cntt==2){
            cout<<min(ans,n)<<endl;
        }else cout<<ans<<endl;
    }
}