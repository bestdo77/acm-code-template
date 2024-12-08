#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=2e5+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
int jipre[N][26],jisuf[N][26],oupre[N][26],ousuf[N][26];//每个点前面的字母t的数量，后面的最大值,独立去跑
int ji[26],ou[26];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    s=" "+s;
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<26;j++){
            jipre[i][j]=jipre[i-1][j];
            oupre[i][j]=oupre[i-1][j];
        }
        if(i%2==1){
            jipre[i][s[i]-'a']=jipre[i-1][s[i]-'a']+1;
            oupre[i][s[i]-'a']=oupre[i-1][s[i]-'a'];
        }else{
            oupre[i][s[i]-'a']=oupre[i-1][s[i]-'a']+1;
            jipre[i][s[i]-'a']=jipre[i-1][s[i]-'a'];
        }
    }//正着跑
    for(int i=n;i>=1;i--){
        for(int j=0;j<26;j++){
            jisuf[i][j]=jisuf[i+1][j];
            ousuf[i][j]=ousuf[i+1][j];
        }
        if(i%2==1){//这样是偶数
            ousuf[i][s[i]-'a']=ousuf[i+1][s[i]-'a']+1;
            jisuf[i][s[i]-'a']=jisuf[i+1][s[i]-'a'];
        }else{
            ousuf[i][s[i]-'a']=ousuf[i+1][s[i]-'a'];
            jisuf[i][s[i]-'a']=jisuf[i+1][s[i]-'a']+1;
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2){
            jipre[i][s[i]-'a']--;
        }else{
            oupre[i][s[i]-'a']--;
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            jisuf[i][s[i]-'a']--;
        }else{
            ousuf[i][s[i]-'a']--;
        }
    }
    if(n%2==0){
        int mj=0,mo=0;
        for(int i=0;i<26;i++){
            mj=max(mj,jipre[n+1][i]);
            mo=max(mo,oupre[n+1][i]);
        }
        cout<<n-mj-mo<<endl;
    }else{
        //分别枚举奇数变a，偶数变a
        int mx=0;
        for(int i=1;i<=n;i++){
            int mo=0,mj=0;
            for(int j=0;j<26;j++){
                mj=max(mj,jipre[i][j]+jisuf[i][j]);
            }
            for(int j=0;j<26;j++){
                mo=max(mo,oupre[i][j]+ousuf[i][j]);
            }
            mx=max(mx,mo+mj);
        }
        // cout<<mj<<" "<<mo<<endl;
        cout<<n-mx<<endl;
    }
    for(int i=0;i<=n+2;i++){
        for(int j=0;j<26;j++){
            jipre[i][j]=oupre[i][j]=jisuf[i][j]=ousuf[i][j]=0;
        }
    }
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