#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=998244353;
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;	
	}
	return re;
}
struct Dsu{
    vector<int> f,rk;
    Dsu(int n){
        f.assign(n+1,0);
        rk.assign(n+1,1);
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    };
    int find(int x){
        if(f[x]!=x) return f[x]=find(f[x]);
        return f[x];
    }
    void join(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if (fx!=fy) {
            if (rk[fx]<rk[fy]) {
                swap(fx,fy);
            }
            f[fy]=fx;
            rk[fx]+=rk[fy];
        }
    }   
};
char a[N1][N1];
int h,w;
int cov(int x,int y){
    return (x-1)*w+y;
}
void Atomatic_AC_machine(){
    cin>>h>>w;
    Dsu dsu(h*w);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(a[i][j]=='#'&&j+1<=w&&a[i][j+1]=='#'){
                dsu.join(cov(i,j),cov(i,j+1));
            }
            if(a[i][j]=='#'&&i+1<=h&&a[i+1][j]=='#'){
                dsu.join(cov(i,j),cov(i+1,j));
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(a[i][j]=='#'&&dsu.find(cov(i,j))==cov(i,j)) cnt++;
        }
    }
    int down=0;
    int up=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(a[i][j]=='#') continue;
            down++;
            set<int> st;
            if(a[i][j+1]=='#') st.insert(dsu.find(cov(i,j+1)));
            if(a[i][j-1]=='#') st.insert(dsu.find(cov(i,j-1)));
            if(a[i+1][j]=='#') st.insert(dsu.find(cov(i+1,j)));
            if(a[i-1][j]=='#') st.insert(dsu.find(cov(i-1,j)));
            up+=cnt-st.size()+1;
        }
    }
    up%=mod;
    cout<<quickpow(down,mod-2)*up%mod<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}