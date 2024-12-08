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
int find(int x){
    x--;    
    return a[(x/3+x%3)%3];
}
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    int sum=0;
    for(int i=0;i<n;i++){ 
        cin>>a[i];
        sum+=a[i];
        if(i!=n-1){
            a[i+n]=a[i];
        }
    }
    // cout<<sum<<endl;
    pre[0]=a[0];
    for(int i=1;i<2*n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=q;i++){
        int l,r,ans1=0;
        cin>>l>>r;
        l--,r--;
        int ans=0;
        //对l处理
        int lseg=l/n;
        int lpos=l%n+lseg;
        int lend=lseg+n-1;
        int rseg=r/n;
        int rpos=r%n+rseg;
        int rfir=rseg;
        if(lpos!=0) ans+=pre[lend]-pre[lpos-1];
        else ans+=pre[lend];
        ans+=pre[rpos]-pre[rfir-1];
        ans+=(rseg-lseg-1)*sum;
        cout<<ans<<endl;
    }
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