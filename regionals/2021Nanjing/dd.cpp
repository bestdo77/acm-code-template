#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
#define endl "\n"
int a[N];
signed main (){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    freopen("data.in","r",stdin);
    freopen("dd.out","w",stdout);
    int t=1;
    // cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int de=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i==1){}
            else{
                if(a[i]==a[i-1]){
                    ans+=de;
                    // cout<<ans;
                }else if(a[i]<a[i-1]){
                    de++;
                    ans+=de;
                    // cout<<ans;
                }else{
                    ans+=2;
                    // cout<<ans;
                }
            }
            // if(i!=n) cout<<" ";
        }
        // cout<<endl;
        cout<<ans<<endl;
    }
}