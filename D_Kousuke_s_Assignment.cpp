#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(auto *p,auto n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
map<int,int> mp;
int pre[N];
int a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    vector<int> dp(n+1,0);
    mp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(mp.contains(pre[i])){
            dp[i]=max(dp[i],dp[mp[pre[i]]]+1);
        }
        mp[pre[i]]=i;
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
    mp.clear();
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}