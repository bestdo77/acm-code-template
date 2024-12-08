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
vector<int> G[N];
int ans=0;
int cntt[N];
long long BinarySearch(long long l,long long r,int *a)
{
    while(l<=r)
    {
        long long mid=(l+r)/2;
        int val=a[mid];
        if(val==2)
        {
            return mid;
        }
        if(val==1)
        {
            // ans++;
            l=mid+1;
        }
        else
        {
            ans++;
            r=mid-1;
        }
    }
    return -1;
}
void solve(){
    // cout<<(int)log2(100)+1<<endl;
    int l,r,k;cin>>l>>r;
    for(int i=0;i<=log2(r-l+1);i++){
        cntt[i]=0;
    }
    int cnt=0;
    for(int p=l;p<=r;p++){
        ans=0;
        for(int i=l;i<=r;i++){
            if(i==p) a[i]=2;
            else if(i>p) a[i]=0;
            else a[i]=1;
        }
        BinarySearch(l,r,a);
        
        // cout<<(double)((p-l+1)*1.0/(r-l+1))<<" "<<ans<<endl;
        cntt[ans]++;
    }
    for(int i=0;i<=log2(r-l+1);i++){
        cout<<cntt[i]<<" ";
    }
    cout<<endl;
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