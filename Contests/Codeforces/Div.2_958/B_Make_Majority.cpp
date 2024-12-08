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
        int n;cin>>n;
        string s;cin>>s;
        string s1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!cnt&&s[i]=='0') s1+='0',cnt=1;
            else if(s[i]=='1') cnt=0,s1+='1';
        }
        int cnt0=0,cnt1=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]=='0') cnt0++;
            else cnt1++;
        }
        if(cnt0<cnt1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}