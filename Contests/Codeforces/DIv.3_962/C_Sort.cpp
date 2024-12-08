#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=2e5+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int pres1[26][N],pres2[26][N];
void solve(){
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    s1=" "+s1;
    s2=" "+s2;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            pres1[j][i]=pres1[j][i-1];
            pres2[j][i]=pres2[j][i-1];
        }
        pres1[s1[i]-'a'][i]=pres1[s1[i]-'a'][i-1]+1;
        pres2[s2[i]-'a'][i]=pres2[s2[i]-'a'][i-1]+1;
    }
    for(int i=1;i<=m;i++){
        int ans=0;
        int l,r;cin>>l>>r;
        for(int j=0;j<26;j++){
            // cout<<char(j+'a')<<endl;
            // cout<<pres1[j][r]-pres1[j][l-1]<<" "<<endl;
            // cout<<pres2[j][r]-pres2[j][l-1]<<" "<<endl;
            int p=abs(pres1[j][r]-pres1[j][l-1]-(pres2[j][r]-pres2[j][l-1]));
            ans+=p;
        }
        cout<<ans/2<<endl;
        // cout<<endl;
        // cout<<ans/2<<endl;
    }
    for(int i=0;i<26;i++){
        for(int j=1;j<=n;j++){
            pres1[i][j]=0;
            pres2[i][j]=0;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}