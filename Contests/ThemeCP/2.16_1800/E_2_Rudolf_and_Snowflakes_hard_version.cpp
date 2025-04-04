#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll __int128
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
map<ll,ll> vis;
void Atomatic_AC_machine(){
    int x;cin>>x;
    int p=4*x-3;
    if((int)sqrt(p)*(int)sqrt(p)==p){
        int p1=sqrt(p);
        if((p1-1)%2==0){
            if(((p1-1)/2)>1){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    if(!vis[x]) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    for(int q=2;q<=1e6;q++){
        ll ans=1+q+q*q;
        ll pq=q*q;
        for(int n=4;n<=100;n++){
            pq*=q;
            ans+=pq;
            vis[ans]=1;
            if(ans>1e18) break;
        }
    }
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}