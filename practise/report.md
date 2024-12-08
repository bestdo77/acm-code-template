## 第一题
求可行的方案数，题面说 $5，1，1$ 和 $1，5，1$ 算一种情况，其实可以转化为求单调不增序列，序列之和为 $n$ 这样序列的个数。dfs 维护父状态的个数。
时间复杂度 $O(n!)$
代码：
```cpp
#include <iostream>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int ans=0;
int n,k;
void dfs(int num,int pos,int mx){//剩几个苹果剩几个盘子当前盘子最多能放多少个
    // cout<<num<<" "<<pos<<" "<<mx<<endl;
    if(pos>k) return;
    if(num==0){ 
        ans++;
        return;
    }
    for(int i=num;i>=0;i--){//拿了num个
        if(i>mx) continue;
        dfs(num-i,pos+1,i);//最多不会超过当前num
    }
}
void Atomatic_AC_machine(){
    cin>>n>>k;
    ans=0;
    dfs(n,0,n);
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}
```
---
## 第二题
观察到每一个图形可以分成九宫格中的五个子图形，这样只需要一直递归直到子图形大小为 $1$ ，放置字符'X'就可以了。
时间复杂度 $O(5^n)$
代码：
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
char ans[1000][1000];
void dfs(int x1,int x2,int y1,int y2){
    // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    if(x1==x2&&y1==y2){
        ans[x1][y1]='X';
        return;
    }
    int len=(x2-x1+1)/3;
    dfs(x1,x1+len,y1,y1+len);
    dfs(x1+2*len,x1+3*len,y1,y1+len);
    
    dfs(x1+len,x1+2*len,y1+len,y1+2*len);
    
    dfs(x1,x1+len,y1+2*len,y1+3*len);
    dfs(x1+2*len,x1+3*len,y1+2*len,y1+3*len);
}
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int mx=pow(3,7-1);
    for(int i=1;i<=mx;i++){
        for(int j=1;j<=mx;j++){
            ans[i][j]=' ';
        }
    }
    // cout<<mx<<endl;
    dfs(1,mx,1,mx);
    int t;
    while(cin>>t){
    if(t==-1) return 0;
       for(int i=1;i<=pow(3,t-1);i++){
            for(int j=1;j<=pow(3,t-1);j++){
                cout<<ans[i][j];
            }cout<<endl;
        }
        cout<<"-"<<endl;
    }
    return 0;
}
```
## 第三题
很典的三角形 dp,转移方程 $dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])$。
时间复杂度$O(n^2)$
```cpp
#include <iostream>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int dp[N1][N1];
int a[N1][N1];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            ans=max(ans,dp[i][j]);
        }
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
```

## 第四题
求最长递增子序列，$dp[i]$ 从前面 $dp[j]$ 最大的且 $a[i]>a[j]$ 的位置转移。
因为数据是 $1000$ 可以暴力 $O(n^2)$，其实可以二分/树状数组做到$O(n\log(n))$。
代码：
```cpp
#include <iostream>
#include <queue>
// #incldue <algorithm>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N],dp[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=1;j<=i-1;j++){
            if(a[i]>a[j]){
                mx=max(mx,dp[j]);
            }
        }
        // cout<<i<<" "<<mx<<endl;
        dp[i]=mx+1;
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
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
```
## 第五题
区间dp
$dp[i][j]$表示区间 $i$ 到 $j$ 变成回文串的花费。
- case $1$: $s[i]==s[j]$ 这样只需要保证从 $i+1$ 到 $j-1$ 是回文串就可以，方程 $dp[l][r]=dp[l+1][r-1]$
- case $2$: $s[i]!=s[j]$ 这样只需要保证从 $i+1$ 到 $j$ （在左端插入s[l]或右端删除s[l]）或者 $i$ 到 $j-1$ 是回文串（在左端插入s[r]或右端删除s[r])。
-  方程 $dp[l][r]=min(dp[l+1][r]+cost[s[l]-'a'],dp[l][r-1]+cost[s[r]-'a'])$。
代码：
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=3e3+10;
const int mod=1e9+7;
string s;
int n,m;
int cost[26];
int dp[N1][N1];
void Atomatic_AC_machine(){
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        char ch;
        int del,add;
        cin>>ch>>del>>add;
        cost[ch-'a']=min(del,add);
    }
    for(int len=1;len<=m;len++){
        for(int l=1;l+len-1<=m;l++){
            int r=l+len-1;
            if(len==1){
                dp[l][r]=0;
            }else{
                if(s[l]!=s[r]) dp[l][r]=min(dp[l+1][r]+cost[s[l]-'a'],dp[l][r-1]+cost[s[r]-'a']);
                else{
                    dp[l][r]=dp[l+1][r-1];
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<endl;
    //     }
    // }
    cout<<dp[1][m]<<endl;
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
```
		