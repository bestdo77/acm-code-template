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
int high[N];
int a[N];
int n,k;
void print(){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>high[i];
    }
    int sum=n;
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    a[n]=0;
    int sum1=0;
    for(int i=1;i<=n;i++){
        sum1+=high[i];
    }
    while(true){
        a[n]++;
        for(int i=n;i>=1;i--){
            if(a[i]==high[i]+1) a[i-1]++,a[i]=1;       
        }
        int sum=0;
        for(int i=n;i>=1;i--){
            sum+=a[i];
        }
        if(sum%k==0) print();
        if(sum==sum1) break;
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