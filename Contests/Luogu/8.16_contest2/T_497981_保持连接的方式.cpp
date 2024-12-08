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
// int a[N];
vector<int> a[N1][N1];
void solve(){
    int n,m,k,t;cin>>n>>m>>k>>t;
    for(int i=1;i<=t;i++){
        int c,x,y;cin>>c>>x>>y;
        if(a[x][y].size()<k){
            a[x][y].push_back(c);
            cout<<-1<<endl;
        }else{
            int p=*min_element(a[x][y].begin(),a[x][y].end());
            int cnt=0;
            for(int i=a[x][y].size()-1;i>=0;i--){
                if(a[x][y][i]==p){
                    // cnt++;
                    break;
                }
                cnt++;
            }
            a[x][y].erase(min_element(a[x][y].begin(),a[x][y].end()));
            cout<<p<<" "<<cnt<<endl;
            a[x][y].push_back(c);
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}