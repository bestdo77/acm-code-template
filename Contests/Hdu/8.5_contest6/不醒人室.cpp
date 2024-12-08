#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
struct node{
    int op,l,r;
}a[N];
bool cmp(node a,node b){
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].op=1;
    }
    for(int i=n+1;i<=n+m;i++){
        cin>>a[i].l>>a[i].r;
        a[i].op=2;
    }
    sort(a+1,a+1+n+m,cmp);
    int sleb=0,skun=0;
    for(int i=1;i<=n+m;i++){
        if(a[i].op==2){
            sleb=a[i].r;
            skun=a[i].r+2*(a[i].r-a[i].l);
            if(a[i].l<a[i-1].r&&a[i-1].op==1){
                cout<<"No"<<endl;
                // cout<<1<<endl;
                return;
            }
        }else{
            if(sleb>a[i].l){
                cout<<"No"<<endl;
                return;
            }
            if(skun<a[i].r){
                cout<<"No"<<endl;
                return;
            }
        } 
    }
    cout<<"Yes"<<endl;
}   
signed main(){
    cout<<pow(3,10)<<endl;
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}