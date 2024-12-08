#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
void solve(){
    int n,m;cin>>n>>m;
    string s1,s2;cin>>s1>>s2;
    s1=" "+s1;s2=" "+s2;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(s1[i]=='#') cnt1++;
        if(s2[i]=='#') cnt2++;
    }
    int p=cnt2/25+1;
    int p1=cnt2%25;
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(s1[i]=='#'){
            if(p){
                s1[i]='a';
                p--;
            }else{
                s1[i]=char('a'+cnt);
                cnt++;
                if(cnt+p1==26) cnt=0,p1=0;
            }
        }
    }
    cout<<s1.substr(1)<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}