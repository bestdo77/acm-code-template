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
int st[64][N];
int pre1[64][N],pre0[64][N];
int ans[64];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<31;i++){
        for(int j=1;j<=n;j++){
            if(a[j]&(1<<i)) st[i][j]=1;
            // cout<<a[j]<<" "<<(1<<i)<<endl;
        }
    }

    for(int i=0;i<31;i++){
        for(int j=1;j<=n;j++){
            st[i][j]+=st[i][j-1];//前缀和，1的个数
        }
    }
    for(int i=0;i<31;i++){
        for(int j=1;j<=n;j++){//pre1前面奇数的个数
            if(st[i][j]%2){
                pre1[i][j]=pre1[i][j-1]+1;
                pre0[i][j]=pre0[i][j-1];
                if(j>=2) ans[i]+=pre0[i][j-2]+1;
                // else if(j==1) ans[i]++;
            }
            else{
                pre1[i][j]=pre1[i][j-1];
                pre0[i][j]=pre0[i][j-1]+1;
                if(j>=2) ans[i]+=pre1[i][j-2];
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<st[0][i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<pre0[1][i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<pre1[1][i]<<" ";
    // }cout<<endl;
    // for(int i=0;i<31;i++){
    //     cout<<ans[i]<<" ";
    // }cout<<endl;
    int ans1=0;
    for(int i=0;i<=31;i++){
        ans1+=(1<<i)*ans[i];
    }
    cout<<ans1<<endl;
    
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