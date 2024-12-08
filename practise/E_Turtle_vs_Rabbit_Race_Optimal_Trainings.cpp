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
int a[N];
int pre[N];
vector<int> G[N];
int cal(int l,int r,int u){
    if(r<l) return -inf;
    int k=pre[r]-pre[l-1];
    return (u+u-k+1)*(k)/2;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int l,u;cin>>l>>u;
        int ll=l-1,rr=n;
        while(ll+1<rr){
            int mid=ll+rr>>1;
            if(pre[mid]-pre[l-1]>u) rr=mid;
            else ll=mid;
        }
        if(cal(l,rr-1,u)>=cal(l,rr,u)) cout<<rr-1<<" ";
        else cout<<rr<<" ";
    }
    cout<<endl;
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