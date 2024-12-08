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
int p[64],cnt,n,zero;//线性基,每一位的线性基
int d[64];
int a[N],b[N];
void insert(int x){//插入一个数x
    for(int i=63;i>=0;i--){
        if(x&(1ll<<i)){
            if(p[i]) x^=p[i];
            else {
                p[i]^=x;
                cnt++;
                break;
            }
        }
    }
}
bool ask(int x){//查询是否有一个数字
    for(int i=63;i>=0;i--){
        if(x&(1ll<<i)){
            if(p[i]) x^=p[i];
        }
    }
    return (x==0);
}
int askmx(){
    int x=0;
    for(int i=63;i>=0;i--){
        if((x^p[i])>x) x^=p[i];
    }
    return x;
}
int askmn(){
    int mn=inf;
    if(cnt==0||n>cnt) return 0;
    else{
        for(int i=0;i<=64;i++){
            if(p[i]) mn=min(mn,p[i]);
        }
        return mn;
    }
}
void rebuild() {
	cnt=0;
	for(int i=63;i>=0;i--)
		for(int j=i-1;j>=0;j--)
			if(p[i]&(1LL<<j)) p[i]^=p[j];
	for(int i=0;i<=63;i++) if(p[i]) d[cnt++]=p[i];
}
int kth(int k) {
	if(k>=(1LL<<cnt)) return -1;
	int ans=0;
	for(int i=63;i>=0;i--)
		if(k&(1LL<<i)) ans^=d[i];
	return ans; 
}

int rank(int x) {
      int ans = 0;
      for(int i = cnt - 1; i >= 0; i --)
                  if(x >= d[i]) ans += (1 << i), x ^= d[i];
      return ans + zero; 
}
void Atomatic_AC_machine(){
    for(int i=0;i<64;i++) p[i]=0;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        insert(x);
    }
    rebuild();
    int m;cin>>m;
    if(n>cnt) zero=1;
    for(int i=1;i<=m;i++){
        int q;cin>>q;
        if(n>cnt&&q==1) cout<<0<<endl;
        else cout<<kth(q-zero)<<endl;
    }
}   
signed main(){
    cout<<sqrt(200000)<<endl; 
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}