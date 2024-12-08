#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
pii a[N];
char dir[N];
pii next_pos(pii pos,char dir,int t){
    if(dir=='E') pos.first+=t;
    else if(dir=='W') pos.first-=t;
    else if(dir=='N') pos.second+=t;
    else if(dir=='S') pos.second-=t;
    return pos;
}
unordered_map<pii,int> mp;
int ans=0;
bool check(int t){
    for(int i=1;i<=n;i++){
        mp[next_pos(a[i],dir[i],t)]++;
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second>>dir[i];
    }   
    return 0;
}