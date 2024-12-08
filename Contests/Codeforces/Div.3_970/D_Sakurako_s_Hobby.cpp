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
int f[N];
int ans[N];
void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}//初始化掌门。掌门是他自己
}
 
int find_f(int x){
	if(x!=f[x]) return f[x]=find_f(f[x]);//把这个子节点的老大换成老大的老大 
	return f[x]; 
}//压缩路径 
 
void join(int x,int y){
	int fx=find_f(x);
	int fy=find_f(y);
	if(fx!=fy) f[fy]=fx;
}//合并子集
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    string s;cin>>s;
    init(n);
    for(int i=1;i<=n;i++){
        int tt=i;
        while(1){
            if(f[a[tt]]==f[tt]) break;
            join(a[tt],tt);
            tt=a[tt];
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<f[i]<<" ";
    // }cout<<endl;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0') ans[f[i]]++;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[f[i]]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++) ans[i]=0;
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