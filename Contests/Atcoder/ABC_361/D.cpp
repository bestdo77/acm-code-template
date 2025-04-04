#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
map<pair<string,int>,int> vis;
queue<pair<string,int>> q;
void Atomatic_AC_machine(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    s=" "+s+"##";
    t=" "+t+"##";
    if(s==t){
        cout<<0<<endl;
        return;
    }
    q.push(make_pair(s,n+1));
    vis[make_pair(s,n+1)]=1;
    while(q.size()){
        pair<string,int> top=q.front();
        int cnt=vis[top];
        q.pop();
        string s=top.first;
        int p=top.second;
        // db(s<<" "<<p<<" "<<cnt)
        // cendl
        for(int i=1;i<=n+1;i++){
            if(s[i]!='#'&&s[i+1]!='#'){
              string ss=s;
              ss[p]=s[i];
              ss[p+1]=s[i+1];
              ss[i]='#';
              ss[i+1]='#';
              if(!vis[make_pair(ss,i)]){
                vis[make_pair(ss,i)]=cnt+1;
                q.push(make_pair(ss,i));
              }  
            }
        }
    }

    if(vis[make_pair(t,n+1)]){
        cout<<vis[make_pair(t,n+1)]-1<<endl;
    }else{
        cout<<-1<<endl;
    }
    return;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}