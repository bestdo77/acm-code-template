#include <bits/stdc++.h>
using namespace std;
int num[600050];
int a[300050],b[300050];
int dp[300050];
int dp2[300050];
int nn[300050];int n;
int res=0;
bool check(int x){
    int cntt=0;
    for (int i=1;i<=n;i++){
        if (a[i]<x&&b[i]>=x)nn[i]=1;
        else if (b[i]<x&&a[i]>=x)nn[i]=-1;
        else nn[i]=0;
        if (a[i]>=x)cntt++;
    }
    int mx=0;
    int mn=0;
    int pre=cntt;
   // cout <<cntt<<endl;
    for (int i=1;i<=n;i++){
        if (dp[i-1]<0)dp[i]=nn[i];
        else dp[i]=dp[i-1]+nn[i];
        mx=max(dp[i],mx);
        if (dp2[i-1]>0)dp2[i]=nn[i];
        else dp2[i]=dp2[i-1]+nn[i];
        mn=min(mn,dp2[i]);
    }
    // cout <<x<<":";
    // for (int I=1;I<=n;I++)cout <<dp[I]<<" ";
    // cout <<endl;
    cntt+=mx;
   // cout <<cntt<<endl;
    // if (cntt>=n/2+1&&pre+mn<=n/2+1){
    //     res=max(res,x);
    // }
    if (cntt>=n/2+1)return 1;
    else return 0;
}
void solve(){
    
    cin >>n;
    int cnt=0;
    for (int i=1;i<=n;i++){
        cin >>a[i]>>b[i];
        num[++cnt]=a[i];
        num[++cnt]=b[i];
    }
    sort (num+1,num+cnt+1);
    int l=1,r=cnt;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(num[mid])){
            l=mid+1;
            res=num[mid];
        }else{
            r=mid-1;
        }
    }
    cout <<res<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // cout<<(1<<20)<<endl;
    cout<<8*7*6*5*4*3*2<<endl;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}





// #include <bits/stdc++.h>
// using namespace std;
// int num[600050];
// int a[300050],b[300050];
// int dp[300050];
// int dp2[300050];
// int nn[300050];int n;
// int res=0;
// bool check(int x){
//     int cntt=0;
//     for (int i=1;i<=n;i++){
//         if (a[i]<=x&&b[i]>x)nn[i]=-1;
//         else if (b[i]<=x&&a[i]>x)nn[i]=1;
//         else nn[i]=0;
//         if (a[i]<=x)cntt++;
//     }
//     int mx=0;
//     int mn=0;
//     int pre=cntt;
//     cout <<cntt<<endl;
//     for (int i=1;i<=n;i++){
//         if (dp[i-1]<0)dp[i]=nn[i];
//         else dp[i]=dp[i-1]+nn[i];
//         mx=max(dp[i],mx);
//         if (dp2[i-1]>0)dp2[i]=nn[i];
//         else dp2[i]=dp2[i-1]+nn[i];
//         mn=min(mn,dp2[i]);
//     }
//     cout <<x<<":";
//     for (int I=1;I<=n;I++)cout <<dp[I]<<" ";
//     cout <<endl;
//     cntt+=mx;
//     cout <<cntt<<endl;
//     if (cntt>=n/2+1&&pre+mn<=n/2+1){
//         res=max(res,x);
//     }
//     if (cntt>n/2+1)return 1;
//     else return 0;
// }
// void solve(){
    
//     cin >>n;
//     int cnt=0;
//     for (int i=1;i<=n;i++){
//         cin >>a[i]>>b[i];
//         num[++cnt]=a[i];
//         num[++cnt]=b[i];
//     }
//     sort (num+1,num+cnt+1);
//     int l=1,r=cnt;
//     while (l<=r){
//         int mid=(l+r)/2;
//         if (check(num[mid])){
//             l=mid+1;
//         }else{
//             r=mid-1;
//         }
//     }
//     cout <<res<<endl;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     int t=1;
//     //cin>>t;
//     while(t--){
//         solve();
//     }
// }