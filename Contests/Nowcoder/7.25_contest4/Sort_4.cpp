#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N],cnt,st[N];
int f[N];
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
    init(n);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        join(x,i);
    }
    for(int i=1;i<=n;i++){
        f[i]=find_f(i);
    }
    for(int i=1;i<=n;i++){
        a[f[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]>1) st[++cnt]=a[i];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<f[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=cnt;i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    int ans=0,cnt2=0;
    for(int i=1;i<=cnt;i++){
        if(st[i]==4) ans++;
        else if(st[i]>4){
            ans+=st[i]/3;
            if(ans%3==2) cnt2++;
        }else if(st[i]==2) cnt2++;
        else if(st[i]==3) ans++;
    }
    ans+=cnt2/2+cnt2%2;
    cout<<ans<<endl;
    for(int i=1;i<=cnt;i++){
        st[i]=0;
    }
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
    cnt=0;
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