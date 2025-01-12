#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
int st;
priority_queue<pii,vector<pii>,greater<pii>> pq;
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        st++;
        a[i]+=pq.size();
        while(pq.size()&&pq.top().first<=st){
            int u=pq.top().second;
            a[u]-=st-u;
            pq.pop();
        }
        if(a[i]!=0) pq.push({a[i]+i,i});
    }
    while(pq.size()){
        int u=pq.top().second;
        a[u]-=st-u;
        pq.pop();
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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