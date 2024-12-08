#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=8;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int n,m;
int a[N];
int b[N];
int hpa[N],hpb[N];
int atta[N],attb[N];
double dfs(int flag){
    double res=0.0;
    int mina=0x3f3f3f3f,minb=0x3f3f3f3f;
    int pa=0,pb=0;
    int na=0,nb=0;
    for(int i=1;i<=n;i++){
        if(hpa[i]<=0) continue;
        else {
            na++;
            if(atta[i]<mina){
                mina=atta[i];
                pa=i;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(hpb[i]<=0) continue;
        else {
            nb++;
            if(attb[i]<minb){
                minb=attb[i];
                pb=i;
            }
        }
    }
    if(na==0&&nb==0) {
        return 0.0;
    }
    if(nb==0) return 1.0;
    if(na==0) return 0.0;
    if(flag==1){
        for(int i=1;i<=m;i++){
            if(hpb[i]>0){
                hpa[pa]-=b[i];
                hpb[i]-=a[pa];
                atta[pa]++;
                res+=(1.0/nb)*dfs(0);
                hpa[pa]+=b[i];
                hpb[i]+=a[pa];
                atta[pa]--;
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(hpa[i]>0){
                hpb[pb]-=a[i];
                hpa[i]-=b[pb];
                attb[pb]++;
                res+=(1.0/na)*dfs(1);
                hpb[pb]+=a[i];
                hpa[i]+=b[pb];
                attb[pb]--;
            }
        }
    }
    return res;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        hpa[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        hpb[i]=b[i];
    }
    double ansa;
    if(n>m) ansa=dfs(1);
    else if(m>n) ansa=dfs(0);
    else ansa=0.5*dfs(1)+0.5*dfs(0);
    swap(m,n);
    for(int i=1;i<=7;i++){
        swap(a[i],b[i]);
        swap(hpa[i],hpb[i]);
    }
    double ansb;
    if(n>m) ansb=dfs(1);
    else if(m>n) ansb=dfs(0);
    else ansb=0.5*dfs(1)+0.5*dfs(0);
    cout<<fixed<<setprecision(12)<<ansa<<" "<<ansb<<" "<<(1-ansa-ansb)<<endl;
}  
signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}