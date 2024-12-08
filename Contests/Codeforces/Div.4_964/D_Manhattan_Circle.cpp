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
vector<char> mp[N];
vector<int> G[N];
int line[N];
int row[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        mp[i].clear();
        line[i]=row[i]=0;
    }
    for(int i=1;i<=m;i++) row[i]=0;
    for(int i=1;i<=n;i++){
        mp[i].push_back('0');
        string s;cin>>s;
        for(int j=1;j<=m;j++){
            mp[i].push_back(s[j-1]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<mp[i][j];
    //     }cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='#') line[i]++,row[j]++;
        }
    }
    // for(int i=1;i<=n;i++) cout<<line[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=m;i++) cout<<row[i]<<" ";
    // cout<<endl;
    int pl=0,pr=0;
    int maxl=0,maxr=0;
    for(int i=1;i<=n;i++){
        if(line[i]>maxl){
            pl=i;
            maxl=line[i];
        }
    }
    for(int i=1;i<=m;i++){
        if(row[i]>maxr){
            pr=i;
            maxr=row[i];
        }
    }
    cout<<pl<<" "<<pr<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}