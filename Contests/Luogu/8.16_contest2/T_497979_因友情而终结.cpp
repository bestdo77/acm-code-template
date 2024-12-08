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
vector<int> G[N];
int pos[N],p;
void solve(){
    string s;cin>>s;
    int ans=0;
    string ss="friend";
    for(int i=0;i<s.size()-5;i++){
        int p1=-1;
        // cout<<s.substr(i,6)<<endl;
        if(s.substr(i,6)==ss){
            p1=i;
            for(int j=p1;j<p1+6;j++){
                s[j]='*';
            }
            pos[++p]=p1;
            i+=4;
        } 
    }
    // cout<<s<<endl;
    int cnt=p;
    for(int i=2;i<=p;i++){
        if(pos[i]-pos[i-1]<=8){
            cnt--;
            i++;
        }
    }
    cout<<cnt<<endl;
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