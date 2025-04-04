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
int cnt[N];
int a[N],c[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cnt[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt[a[i]]>=2){
            c[i]=0;
        }else{
            c[i]=1;
        }
    }
    int ansl=0,ansr=0;
    int mx=0;
    bool flag=0;
    int l=0;
    for(int i=1;i<=n;i++){
        if(c[i]==1&&!flag){
            l=i,flag=1;
        }else if(c[i]==0){
            flag=0;
            if(i-l>mx&&c[i-1]!=0){
                mx=i-l;
                ansl=l;
                ansr=i-1;
            }
        }
    }
    if(c[n]==1&&n-l+1>mx){
        mx=n-l+1;
        ansl=l;
        ansr=n;
    }
    // cout<<mx<<endl;
    if(!ansl&&!ansr) cout<<0<<endl;
    else cout<<ansl<<" "<<ansr<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}