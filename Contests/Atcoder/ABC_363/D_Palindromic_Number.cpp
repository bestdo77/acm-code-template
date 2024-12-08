#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N],b[N];
vector<array<int,element>> v;
int p10[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p10[1]=10;
    for(int i=2;i<=18;i++){
        p10[i]=p10[i-1]*10;
    }
    int n;cin>>n;
    if(n<10){
        cout<<n-1<<endl;
        return 0;
    }
    a[1]=9;
    for(int i=2;i<=36;i++){
        if(i%2==0) a[i]=a[i-1];
        else a[i]=a[i-1]*10;
    }
    // for(int i=1;i<=n;i++){
    //      cout<<a[i]<<" ";
    // }
    a[1]=a[2]=10;
    for(int i=1;i<=36;i++){
        b[i]=b[i-1]+a[i];
    }
    // for(int i=1;i<=n;i++){
    //       cout<<b[i]<<" ";
    // }
    int len=0;
    for(int i=1;i<=36;i++){
        if(b[i]>n){
            len=i;
            break;
        }
    }
    int ans=n-b[len-1];
    // cout<<ans<<endl;
    ans+=p10[(len)/2+(len)%2-1];
    // cout<<ans<<endl;
    // cout<<ans<<endl;
    string s=to_string(ans);
    // cout<<s<<endl;
    // cout<<len<<endl;
    // cout<<len<<endl;
    string tmp=s.substr(0,len/2);
    reverse(tmp.begin(),tmp.end());
    s+=tmp;
    cout<<s<<endl;
    return 0;
}