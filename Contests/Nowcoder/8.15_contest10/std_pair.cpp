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
map<string,int> mp;
#define ls node<<1
#define rs node<<1|1
int tr[N1][N1];
string inr="int";
string dor="double"; 
int vis[N1];
// void dfs(string s,int p,int tt,int node){
//     if (vis[node]) return;
//     vis[node]=1;
//     cout <<tt<<" "<<node<<endl;
    
//     //if(tt>=s.size()) return;
//     string tmp="";
//     for(int i=tt;i<s.size();i++){
        
//         if(s[i]=='<'){
//             dfs(s,p,i+1,ls);
//         }
//         if(s[i]==','){
//             if(tmp==inr) tr[p][node]=1;
//             if(tmp==dor) tr[p][node]=2;
//             dfs(s,p,i+1,node+1);
//         }
//         if(s[i]=='>'){
//             if(tmp==inr) tr[p][node]=1;
//             if(tmp==dor) tr[p][node]=2;
//             dfs(s,p,i+1,(node-1)/2);
//         }
//         tmp+=s[i];
//     }
//     if(tmp==inr) tr[p][node]=1;
//     if(tmp==dor) tr[p][node]=2;
// }
void solve(){
    int p=0;
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;cin>>s1>>s2;
        s2.erase(s2.size()-1);
        mp[s2]=++p;
        int node=1;
        string tmp="";
        int now=0;
        int past=0;
        for(int j=0;j<s1.size();j++){
            if(s1[i]=='')
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            cout<<tr[i][j]<<" ";
        }cout<<endl;
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