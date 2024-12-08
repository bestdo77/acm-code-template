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
int cnt=0;
map<string,int> mp;
int tr[N1][N1];
string inr="int";
string dor="double"; 
struct node{
    int fa,ls,rs;
}a[N1][N1];
int ans[N1][N1];
int p[N];
string s[N];
int flag=0;
int ansff=0;
int getans(int now){
    int t=ansff;
    if (ans[t][now]==0){
        cout <<"pair<";
        getans(a[t][now].ls);
        cout <<",";
        getans(a[t][now].rs);
        cout <<">";
    }
    else if (ans[t][now]==1)cout <<"int";
    else if (ans[t][now]==2)cout <<"double";
}
void dfs(int now,int tt,int t){
    
    if(flag) return;
    string tmp="";
    int fa=a[t][now].fa;
    for(int i=tt;i<s[t].size();i++){
        cnt++;
        if(s[t][i]=='<'){
            if(a[t][now].ls==0){
                a[t][now].ls=++p[t];
                a[t][p[t]].fa=now;
            }//左儿子
            // if(a[t][now].ls==p[t]) 
            if(tmp==inr) ans[t][now]=1;
            if(tmp==dor) ans[t][now]=2;
            dfs(p[t],i+1,t);
            break;
        }
        if(s[t][i]==','){//处于左儿子的状态
            if(a[t][fa].rs==0){
                a[t][fa].rs=++p[t];
                a[t][p[t]].fa=fa;
            }
            // if(a[t][now].rs==p[t]) 
            if(tmp==inr) ans[t][now]=1;
            if(tmp==dor) ans[t][now]=2;
            dfs(p[t],i+1,t);
            break;
        }
        if(s[t][i]=='>'){//处于右儿子
            // cout<<"!!!"<<endl;
            if(tmp==inr) ans[t][now]=1;
            if(tmp==dor) ans[t][now]=2;
            dfs(fa,i+1,t);
            break;
        }
        if(i==s[t].size()-1){
            if(tmp==inr) ans[t][now]=1;
            if(tmp==dor) ans[t][now]=2;
            flag=1;
        }
        tmp+=s[t][i];
    }
    if(tmp==inr) ans[t][now]=1;
    if(tmp==dor) ans[t][now]=2;
}
int sch(string s){
    string st=s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            st=s.substr(0,i);
            break;
        }
    }
    int t=mp[st];int now=1;
    for (int i=0;i<s.size();i++){
        if (s[i]=='.'){
            if (s[i+1]=='f')now=a[t][now].ls;
            else now=a[t][now].rs;
        }
    }
    ansff=t;
    //cout <<st<<" "<<t<<endl;
    //cout <<now<<endl;
    return now;
}
void solve(){
    int p1=0;
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        flag=0;
        string s2;
        cin>>s[i]>>s2;
        s2.erase(s2.size()-1);
        mp[s2]=++p1;
        a[p1][1].fa=1;
        dfs(++p[p1],0,p1);
    }
    for (int i=1;i<=q;i++){
        string s;
        cin >>s;
        getans(sch(s));
        cout <<endl;
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