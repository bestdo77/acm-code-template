#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int h[N],p[N];
int n,m,k;
pii a[2*N];
bool check(int atk){
    for(int i=1;i<=n;i++){
        int gong=h[i]/atk+!!(h[i]%atk);
        if(gong>m){
            a[i]=a[i+n]={0,0};
            continue;
        }
        int l=p[i]-(m-gong);
        int r=p[i]+(m-gong);
        a[i]=make_pair(l,1);
        a[i+n]=make_pair(r+1,-1);    
    }
    sort(a+1,a+1+2*n);
    int re=0;
    for(int i=1;i<=2*n;i++){
        re+=a[i].second;
        // if(a[i+1].first==a[i].first) continue;
        if(re>=k) return true;
    }
    return false;
}
void Atomatic_AC_machine(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    int l=0,r=2e9+10;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid;
    }
    if(r!=2e9+10) cout<<r<<endl;
    else cout<<-1<<endl;
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