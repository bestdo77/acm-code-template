#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N],id;
pair<int,int> ans[N];
int re[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    id=0;
    for(int i=1;i<=n;i++){
        if(a[i]>ans[id].first){
            ans[++id]={a[i],i};
        }
    }
    int mn=inf;
    for(int j=ans[id].second;j<=n;j++){
        mn=min(a[j],mn);
    }
    if(mn<ans[id-1].first) ans[id-1].first=ans[id].first;
    for(int i=id-1;i>=2;i--){
        for(int j=ans[i].second;j<=ans[i+1].second;j++){
            mn=min(a[j],mn);
        }
        if(mn<ans[i-1].first){
            ans[i-1].first=ans[i].first;
        }
    }
    ans[id+1].second=n;
    for(int i=1;i<=id;i++){
        for(int j=ans[i].second;j<=ans[i+1].second;j++){
            re[j]=ans[i].first;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<re[i]<<" ";
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