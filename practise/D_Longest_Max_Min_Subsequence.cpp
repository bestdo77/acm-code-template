#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> v,vis(n+1,0),last(n+1,0);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(vis[a[i]]) continue;
        // cout<<a[i]<<" "<<v.size()<<endl;
        while((v.size()%2==0)?(v.size()>0&&a[i]<v.back()&&i<last[v.back()]):(v.size()>0&&a[i]>v.back()&&i<last[v.back()])){
            vis[v.back()]=0;
            v.pop_back();
        }
        while((v.size()%2==0)?(v.size()>1&&a[i]>v[v.size()-2]&&i<last[v[v.size()-2]]&&i<last[v[v.size()-1]]):(v.size()>1&&a[i]<v[v.size()-2]&&i<last[v[v.size()-2]]&&i<last[v[v.size()-1]])){
            // cout<<"22222"<<endl;
            vis[v.back()]=0;
            v.pop_back();
            vis[v.back()]=0;
            v.pop_back();
        }
        v.push_back(a[i]);
        vis[a[i]]=1;
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
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