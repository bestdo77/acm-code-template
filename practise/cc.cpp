#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;
#define int long long
#define pii pair<int,int>
string ch[N];
const int MAX=1e6+10;
int f[MAX];
vector <int>row[N],col[N];
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
int quickpow(int x,int y){
	int re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod,y=y/2;//2的y次方等于4的y/2次方.	
	}
	return re;
}
int n,m;
int cnt[N]; 
int visr[N];
int vis[N];
queue<int> q;
void BFS(int i){
    while (!q.empty()){
        q.pop();
    }
    q.push(i);
    while (!q.empty()){
        int tem=q.front();
      //  cout <<tem<<endl;
       q.pop();
        if(visr[tem]) continue;
        visr[tem]=1;
        for (auto c:row[tem]){
                for (auto rr:col[c]){
                    if (!visr[rr]){
                        q.push(rr);
                        visr[rr]=1;
                        join(i,rr);
                    }
                }
                for (auto rr:col[m-c+1]){
                    if(!visr[rr]){
                        q.push(rr);
                        visr[rr]=1;
                        join(i,rr);
                    }
                }
        }
    }
}
void solve(){
    cin>>n>>m;
    for (int i=0;i<=n+3;i++){
        row[i].clear();
        visr[i]=0;
        vis[i]=0;
        col[i].clear();
        cnt[i]=0;
    }
    for (int i=0;i<=m+3;i++){
        row[i].clear();
        visr[i]=0;
        vis[i]=0;
        col[i].clear();
        cnt[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>ch[i];
        ch[i]=" "+ch[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ch[i][j]=='1'){
                cnt[j]++;
                col[j].push_back(i);
                row[i].push_back(j);
            } 
        }
    }
    int ans=0;
    for(int i=1;i<=m/2;i++){
        if(cnt[i]+cnt[m-i+1]>2){
            cout<<0<<endl;
            return;
        }
    }
    if(m%2&&cnt[m/2+1]>1){
        cout<<0<<endl;
        return;
    }
    init(n+5);
    for (int i=1;i<=n;i++){
        if (!visr[i])BFS(i);
    }
    int res=0;
    for (int i=1;i<=n;i++){
        if (find_f(i)==i)res++;
    }
   // cout <<cnt<<endl;
    cout <<quickpow(2,res)<<endl;
}
signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}