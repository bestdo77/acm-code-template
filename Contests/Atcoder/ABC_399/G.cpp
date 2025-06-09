#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;
map<pii,int> vis;
vector<int> e[N];
int din[N];
int vis2[26];
void dfs(int u){
    if(vis2[u]) return;
    vis2[u]=1;
    for(auto v:e[u]){
        dfs(v);
    }
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    int ans=0;
    set<int> st;
    for(int i=0;i<n;i++){
		if(e[s[i]-'a'].size()&&e[s[i]-'a'][0]!=t[i]-'a'){
			cout<<-1;
			return;
		}
		if(e[s[i]-'a'].size()==0&&s[i]!=t[i]) ans++,din[t[i]-'a']++;
		st.insert(t[i]-'a');
		e[s[i]-'a'].push_back(t[i]-'a');	
	}
    
    queue<int> q;
    for(int i=0;i<26;i++){
        if(!din[i]) q.push(i);
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        vis2[u]=1;
        for(auto v:e[u]){
            --din[v];
            if(!din[v]) q.push(v);
        }
    }
    if(st.size()==26){
		int f=0;
		for(int i=0;i<n;i++) f+=(s[i]!=t[i]);
		if(f) cout<<-1;
		else cout<<0;
		return;
	}
    int cnt=0;
    for(int i=0;i<26;i++){
        if(!vis2[i]){//成环了
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}