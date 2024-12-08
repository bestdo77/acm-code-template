#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    if(s.size()>3){
        for(auto it:s){
            if(it=='0'){
                cout<<0<<endl;
                return;
            }
        }
    }
    if(s.size()==2){
        cout<<10*(s[0]-'0')+s[1]-'0'<<endl;
        return;
    }
    if(s.size()==3){
        a[1]=s[0]-'0'+10*(s[1]-'0')+s[2]-'0';
        a[2]=s[2]-'0'+10*(s[0]-'0')+s[1]-'0';
        a[3]=(s[0]-'0')*(10*(s[1]-'0')+s[2]-'0');
        a[4]=(s[2]-'0')*(10*(s[0]-'0')+s[1]-'0');
        ans=a[1];
        for(int i=1;i<=4;i++){
            ans=min(ans,a[i]);
        }
        cout<<ans<<endl;
        return;
    }
    
    ans=inf;
    for(int i=0;i<s.size()-1;i++){
        int tmp=10*(s[i]-'0')+s[i+1]-'0';
        for(int j=0;j<s.size();j++){
            if(j==i||j==i+1) continue;
            if(s[j]!='1') tmp+=s[j]-'0';
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return;
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