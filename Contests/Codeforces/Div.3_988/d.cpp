#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
pii hul[N];
pii add[N];
priority_queue<int> q;
void Atomatic_AC_machine(){
    int n,m,D;cin>>n>>m>>D;
    for(int i=1;i<=n;i++){
        cin>>hul[i].first>>hul[i].second;
        hul[i].second=hul[i].second-hul[i].first+1;
    }
    for(int i=1;i<=m;i++){
        cin>>add[i].first>>add[i].second;
    }
    int jp=0;
    int ans=0;
    for(int i=1,j=1;i<=n;i++){
        // cout<<i<<" "<<j<<endl;
        while(add[j].first<hul[i].first&&j<=m){
            q.push(add[j].second);
            j++;
        }
        while(jp<hul[i].second){
            if(q.size()==0){
                cout<<"-1"<<endl;
                return;
            }
            ans++;
            jp+=q.top();
            q.pop();
        }
    }
    cout<<ans<<endl;
    while(q.size()){
        q.pop();
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