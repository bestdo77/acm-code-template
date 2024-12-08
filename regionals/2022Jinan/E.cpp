#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    if(k>n/2){
        cout<<"Yes"<<endl;
    }
    else if(k%2==0){
        cout<<"Yes"<<endl;
    }
    else{
        int sb = n/k;
        int max0 ;
        if(n%k > k/2){
            max0 = k/2 - (n%k - k/2);
        }
        else max0 = n%k;

        if(max0>=sb - 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    //    int cnt0=0,cnt1=0;
    //    cnt0+=(n/k)*(k/2);
    //    cnt1+=(n/k)*(k/2+1);
    //    if (n%k>k/2){
    //         cnt0+=k/2;
    //         cnt1+=(n%k-k/2);
    //    }else cnt0+=n%k;
    //    if (cnt0==n/2&&cnt1==(n/2+n%2))cout <<"Yes"<<endl;
    //    else cout <<"No"<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}