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
int dp[N];//表示以N为终点的所有子序列的价值
int dp1[N];
int pre[N];
int last[N];//表示每个数前一次出现的位置
vector<int> G[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1]=1;
    last[a[1]]=1;
    set<int> st;
    for(int i=1;i<=n;i++){
        st.insert(a[i]);
        dp1[i]=st.size();
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+dp1[i];
    }
    st.clear();
    for(int i=2;i<=n;i++){
        st.insert(a[i]);
        dp[i]=dp[i-1]+i-last[a[i]];
        last[a[i]]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[i];
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