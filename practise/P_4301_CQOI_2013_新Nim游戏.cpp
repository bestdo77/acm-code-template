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
vector<int> G[N];
int p[64],cnt;
void insert(int x){
    for(int i=62;i>=0;i--){
        if(x&(1ll<<i)){
            if(p[i]) x^=p[i];
            else{
                p[i]=x;
                break;
            }
        }
    }
}
bool check(int x){
    for(int i=62;i>=0;i--){
        if(p[i]&&(x&(1ll<<i))){
            x^=p[i];
        } 
    }
    return x==0;
}
bool cmp(int x1,int x2){
    return x1>x2;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(check(a[i])){
            ans+=a[i];
        }else insert(a[i]);
    }
    cout<<ans<<endl;
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