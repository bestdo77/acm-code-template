#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int lcm(int x,int y){
    if(x>2e9||y>2e9) return inf;
    if(y==0) return x;
    return x*y/__gcd(x,y);
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> a(n);
    map<int,int> vis;
    for(int i=0;i<n;i++){
        cin>>a[i];
        vis[a[i]]=1;
    }
    int _lcm=0;
    for(int i=0;i<n;i++){
        _lcm=lcm(a[i],_lcm);
    }
    // cout<<_lcm<<endl;
    sort(a.begin(),a.end());
    if(_lcm>a[n-1]) cout<<n<<endl;
    else{
        int ans=0;
        for(int i=1;i<=sqrt(_lcm)+1;i++){
            if(_lcm%i==0){
                int __lcm=0;
                int cnt=0;
                for(int j=0;j<n;j++){
                    if(i%a[j]==0){
                        __lcm=lcm(a[j],__lcm);       
                        cnt++;
                    }
                }
                if(__lcm==i&&!vis[i]) ans=max(ans,cnt);
                
                int p=_lcm/i;
                // cout<<i<<" "<<p<<endl;
                __lcm=0;
                cnt=0;
                for(int j=0;j<n;j++){
                    if(p%a[j]==0){
                        __lcm=lcm(a[j],__lcm);       
                        cnt++;
                    }
                }
                if(__lcm==p&&!vis[p]){ 
                    // cout<<p<<" "<<ans<<endl;
                    ans=max(ans,cnt);
                }
            }

        }
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