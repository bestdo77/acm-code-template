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
string tt[N];
int last[N];
void solve(){
    int n;cin>>n;
    int len=0;
    string ts=" ";
    for(int i=1;i<=n;i++){
        cin>>tt[i];
        len=max(len,(int)tt[i].size());
        tt[i]=" "+tt[i];
    }
    for(int i=1;i<=log2(len)+1;i++){
        ts+=ts;
    }
    for(int i=1;i<=n;i++){
        tt[i]+=ts;
    }
    //遍历每一列
    for(int i=1;i<=len;i++){
        for(int j=n;j>=1;j--){
            if(tt[j][i]!=' ') last[i]=j;
        }
    }
    // for(int i=1;i<=len;i++) cout<<last[i]<<" ";

    for(int i=1;i<=len;i++){
        for(int j=n;j>=last[i];j--){
            if(tt[j][i]==' ') cout<<'*';
            else cout<<tt[j][i];
        }
        cout<<endl;
    }
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