#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        string s;cin>>s;
        s=" "+s;
        for(int i=1;i<=m;i++){
            int l,r;cin>>l>>r;
            string sl=s.substr(1,l-1);
            string sr=s.substr(r+1,n);
            if(sl.find(s[l])!=string::npos||sr.find(s[r])!=string::npos){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
        }
    }
    return 0;
}