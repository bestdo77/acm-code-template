#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int M=61000;
const int N=301;
#pragma GCC optimize(3,"Ofast","inline")
bitset<N> ch[M][26];//每个bitset表示第i位第j个字母第k个字符串是否和j不同
bitset<N> A,C;
int ans[N];
int n,q,m,K;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q>>m>>K;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        s=" "+s;
        for(int j=1;j<=m;j++){
            for(int k=0;k<26;k++){
                if(s[j]-'a'!=k) ch[j][k].set(i);//不同
            }
        }
    }
    // cout<<ch[1]['k'-'a']<<endl;
    for(int i=1;i<=q;i++){
        string s;cin>>s;
        s=" "+s;
        memset(ans,0,sizeof(ans));
        for(int j=1;j<=n;j++) A.set(j);
        for(int j=1;j<=m;j++){
            C=A&ch[j][s[j]-'a'];
            for(auto k=C._Find_first();k!=C.size();k=C._Find_next(k)){
                if((++ans[k]>K)) A[k]=0;
            }
        }
        cout<<A.count()<<endl;
    }
    return 0;
}