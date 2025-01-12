#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int f[N];
int col[N];
int son[N];
int cntcol[N];
int l[N],r[N];
void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
        col[i]=i;
        son[i]=1;
        cntcol[i]=1;
        l[i]=r[i]=i;
    }
}
 
int find_f(int x){
	if(x!=f[x]) {
        return f[x]=find_f(f[x]);
    }
    return f[x]; 
} 
 
void join(int x,int y){
	int fx=find_f(x);
	int fy=find_f(y);
	if(fx!=fy) {
        f[fy]=fx;
        l[fx]=min(l[fx],l[fy]);
        r[fx]=max(r[fx],r[fy]);
        son[fx]+=son[fy];//儿子挂到爹上
        son[fy]=0;
    }
}//合并子集
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    init(n);
    for(int i=1;i<=q;i++){
        int op;cin>>op;
        if(op==1){
            int x,c;cin>>x>>c;
            int ncol=col[find_f(x)];
            int nsz=son[find_f(x)];
            if(ncol!=c){
                int lx=l[find(x)],rx=r[find(x)];
                if(col[find(lx-1)]==c||col[find(rx+1)]==c){
                    if(col[find(lx-1)]==c) join(find(lx-1),x);
                    if(col[find(rx+1)]==c) join(find(rx+1),x);
                }
                col[find_f(x)]=c;
                cntcol[ncol]-=nsz;
                cntcol[c]+=nsz;
            }
        }else{
            int c;cin>>c;
            cout<<cntcol[c]<<endl;
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}