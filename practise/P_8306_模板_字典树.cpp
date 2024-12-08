#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=3e6;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
char s[N];
int ch[N][80],cnt[N],idx;
void insert(char *s){
    int p=0;//表示当前所在的树的节点
    for(int i=0;s[i];i++){
        int j=s[i]-'0';
        if(!ch[p][j]) ch[p][j]=++idx;
        p=ch[p][j];
        cnt[p]++;
    }
    // cnt[p]++;这里写和for循环里面去写，有区别，一个是会改变一条路径，另一个是只改变点。
}
int query(char *s){//查询是否在里面，
    int p=0;
    for(int i=0;s[i];i++){
        int j=s[i]-'0';
        if(!ch[p][j]) return 0;
        p=ch[p][j];
    }
    return cnt[p];
}
void solve(){
    int n,q;cin>>n>>q;
    int len=0;
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        insert(s);
        len=max(len,(int)strlen(s));
    }
    for(int i=1;i<=q;i++){
        scanf("%s",s);
        cout<<query(s)<<endl;
    }
    for(int i=0;i<=idx;i++){
        for(int j=0;j<80;j++){
            ch[i][j]=0;
        }
    }
    for(int i=0;i<=idx;i++){
        cnt[i]=0;
    }
    idx=0;
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}