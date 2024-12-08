#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<long long,long long>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
long long n,k;
pii p[N],q[N];
int minval(int x,int kk){
    //两个产品，效能和单价，还有需要的总效能，返回单价
    int ans=inf;
    for(int i=0;i<=1000;i++){
        int c1=i*p[x].second;
        if(i*p[x].first<kk){//如果效能小于mid
            c1+=((int)ceil(1.0*(kk-i*p[x].first)/q[x].first))*q[x].second;
        }
        int c2=i*q[x].second;
        if(i*q[x].first<kk){
            c2+=((int)ceil(1.0*(kk-i*q[x].first)/p[x].first))*p[x].second;
        }
        ans=min({ans,c1,c2});
    }
    return ans;
}
bool check(int kk){
    int val=0;
    for(int i=1;i<=n;i++){
        val+=minval(i,kk);
    }
    return val<=k;
}
void Atomatic_AC_machine(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second>>q[i].first>>q[i].second;
    }
    int l=-1,r=1e15;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    long long ll=l;
    cout<<ll<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}