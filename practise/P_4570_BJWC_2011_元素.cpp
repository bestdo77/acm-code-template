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
    int x,y;
}a[N];
bool cmp(node a,node b){
    if(a.y==b.y) return a.x>b.x;
    else return a.y>b.y;
}
vector<int> G[N];
int p[64];
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
        if((x&(1ll<<i))&&p[i]){
            x^=p[i];
        }
    }
    return x==0;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!check(a[i].x)){
            ans+=a[i].y;
            insert(a[i].x);
        }
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