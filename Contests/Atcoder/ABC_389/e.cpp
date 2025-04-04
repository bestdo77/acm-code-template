#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define int __int128
#define ll long long
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int a[N];
int buy[N];
int n,w;
bool check(int x){
    int sum=0;
    for(int i=1;i<=n;i++){
        int ans=((x-1)/a[i]+1)/2;
        sum+=ans*ans*a[i];
        if(sum>w) return false;
    }
    return sum<=w;
}
priority_queue<pii,vector<pii>,greater<pii>> pq;
void Atomatic_AC_machine(){
    ll n1,w1;
    cin>>n1>>w1;
    n=n1,w=w1;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        a[i]=x;
    }
    int l=-1,r=w+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    int x=l;
    int cnt=0;
    // cerr<<x<<endl;
    for(int i=1;i<=n;i++){
        int ans=((x-1)/a[i]+1)/2;
        cnt+=ans;
        buy[i]=ans+1;
        pq.push({(2*buy[i]-1)*a[i],i});
        w-=ans*ans*a[i];
    }
    int ans=0;
    // db(w)
    while(w){
        pii top=pq.top();
        int cost=top.first;
        // db(cost)
        // cendl
        pq.pop();
        if(w<cost) break;
        int p=top.second;
        buy[p]++;
        pq.push({(2*buy[p]-1)*a[p],a[p]});
        cnt++;
        w-=cost;
    }
    ll cnt1=cnt;
    cout<<cnt1<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        //cout << "Case #" << i << ": ";
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}