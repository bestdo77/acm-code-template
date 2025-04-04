#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct inv{
    int l,r,id;
}a[N];
bool cmp1(inv a,inv b){
    if(a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}
bool cmp2(inv a,inv b){
    if(a.r==b.r) return a.l>b.l;
    return a.r<b.r;
}
set<int> rr;
set<int> ll;
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }
    vector<int> ans(n+1,0);
    sort(a+1,a+1+n,cmp1);
    for(int i=2;i<=n;i++){
        int r=a[i].r;
        rr.insert(a[i-1].r);
        int j=i+1;
        if(rr.lower_bound(r)!=rr.end()){
            r=*rr.lower_bound(r);
            ans[a[i].id]+=max(r-a[i].r,0ll);
        }
    }
    sort(a+1,a+1+n,cmp2);
    for(int i=n-1;i>=1;i--){
        int l=a[i].l;
        ll.insert(a[i+1].l);
        auto it=ll.upper_bound(l);
        if((it)!=ll.begin()){
            l=*(--it);
            ans[a[i].id]+=max(a[i].l-l,0ll);
        }
    }
    // for(int i=1;i<=n;i++){
    //     if(i+1<=n&&a[i+1].l==a[i].l&&a[i].r==a[i+1].r) ans[a[i].id]=ans[a[i+1].id]=0;
    // }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    rr.clear();
    ll.clear();
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}