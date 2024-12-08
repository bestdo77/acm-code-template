#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
char G[100][100];
void solve(){
    int n,m;pii st;
    cin>>n>>m;
    cin>>st.first>>st.second;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>G[i][j];
        }
    }
    string s;cin>>s;
    int len=s.length();s=" "+s;
    for(int i=1;i<=len;i++){
        int x=st.first,y=st.second;
        if(s[i]=='L'&&G[x][y-1]=='.'&&x<=n&&x>=1&&y-1<=m&&y-1>=1) st={x,y-1};
        else if(s[i]=='R'&&G[x][y+1]=='.'&&x<=n&&x>=1&&y+1<=m&&y+1>=1) st={x,y+1};
        else if(s[i]=='U'&&G[x-1][y]=='.'&&x-1<=n&&x-1>=1&&y<=m&&y>=1) st={x-1,y};
        else if(s[i]=='D'&&G[x+1][y]=='.'&&x+1<=n&&x+1>=1&&y<=m&&y>=1) st={x+1,y};
        // cout<<st.first<<" "<<st.second<<endl;
    }
    cout<<st.first<<" "<<st.second<<endl;
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