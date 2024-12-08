#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<int> stacks;
    int q;cin>>q;
    int sum=0;
    for(int i=1;i<=q;i++){
        int del,x;cin>>del>>x;
        for(int j=1;j<=del;j++){
            sum-=(stacks.size())*stacks.top();
            // cout<<sum<<endl;
            sum=(sum+mod)%mod;
            stacks.pop();
        }
        stacks.push(x);
        sum+=stacks.size()*x%mod;
        cout<<(sum+mod)%mod<<endl;
    }
    return 0;
}