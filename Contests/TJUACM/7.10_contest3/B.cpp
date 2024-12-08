#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int MAXN=1e3+10;
int a[MAXN],b[MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int ans=0;
        for(int i=s.length()-1;i>=0;--i){
            if(i==0||(s[i]==s[i-1])) ans++;
            else ans+=i+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}