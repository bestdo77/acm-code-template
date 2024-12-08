#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int s[N],n;
int lowbit(int x){
    return x&(-x);
}
void modify(int x,int v){
    while(x<=n){ 
        s[x]+=v,x+=lowbit(x);
    }
}
int query(int x){
    int re=0;
    while(x){
        re+=s[x];
        x-=lowbit(x);
    }
    return re;
}
void Atomatic_AC_machine(){
    cin>>n;
    int ans=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b=a;
    sort(b.begin(),b.end());
    int sz=unique(b.begin(),b.end())-b.begin();
    for(int i=n-1;i>=0;i--){
        int p=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
        ans+=query(p-1);
        modify(p,1);
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