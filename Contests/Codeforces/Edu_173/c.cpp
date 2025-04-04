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
int a[N];
int pre[N];
int qmx(int l,int r){
    int dp=0;
    int res=0;
    for(int i=l;i<=r;i++){
        dp+=a[i];
        res=max(dp,res);
        dp=max(dp,0ll);
    }
    return res;
}
int qmn(int l,int r){
    int dp=0;
    int res=0;
    for(int i=l;i<=r;i++){
        dp+=-a[i];
        res=max(dp,res);
        dp=max(dp,0ll);
    }
    return -res;
}
void Atomatic_AC_machine(){
    int n,pos;
    cin>>n;
    pos=n+1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        if(a[i]!=1&&a[i]!=-1) pos=i; 
    }
    int l1=min(qmn(1,pos-1),qmn(pos+1,n)),r1=max(qmx(1,pos-1),qmx(pos+1,n));
    int l2=inf,r2=-inf;
    if(pos!=n+1){
        int mn=inf,mx=-inf;
        for(int i=pos;i<=n;i++){
            mn=min(mn,pre[i]);
            mx=max(mx,pre[i]);
        }
        for(int i=0;i<pos;i++){
            l2=min(l2,mn-pre[i-1]);
            r2=max(r2,mx-pre[i-1]);
        }
        mn=inf,mx=-inf;
        for(int i=0;i<pos;i++){
            mn=min(mn,pre[i]);
            mx=max(mx,pre[i]);
        }
        for(int i=pos;i<=n;i++){
            l2=min(l2,pre[i]-mx);
            r2=max(r2,pre[i]-mn);
        }
    }else l2=0,r2=0;
    db(l1<<" "<<r1<<" "<<l2<<" "<<r2)
    if(l1>l2){
        swap(l1,l2);
        swap(r1,r2);
    }
    cendl
    vector<int> ans;
    for(int i=l1;i<=r1;i++){
        ans.emplace_back(i);
    }
    for(int i=max(r1+1,l2);i<=r2;i++){
        ans.emplace_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
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