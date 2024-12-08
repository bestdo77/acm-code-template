#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
const int mod = 998244353;
string s;
int last [70][10];
int sum[10];
int dp[70][10];
int idx(char x){
    if(x>='a'&&x<='z') return x-'a';
    else if(x>='A'&&x<='Z') return x-'A'+26;
    else return x-'0'+52;
}
const int aa=1,AA=2,num=4;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >>n>>s;
    s=' '+s;
    sum[0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=62;j++){
            for (int k=0;k<=7;k++){
                dp[j][k]=0;
            }
        }
        if ((s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
            int x=idx(s[i]);
            if ((s[i]>='A'&&s[i]<='Z')){
                for (int j=0;j<=7;j++){
                    dp[x][j|AA]+=mod+sum[j]-last[x][j];
                    dp[x][j|AA]%=mod;
                }
            }
            if ((s[i]>='0'&&s[i]<='9')){
                for (int j=0;j<=7;j++){
                    dp[x][j|num]+=mod+sum[j]-last[x][j];
                    dp[x][j|num]%=mod;
                }
            }
        }
        else if (s[i]>='a'&&s[i]<='z'){
            int x=idx(s[i]);
            int y=x+26;
            for (int j=0;j<=7;j++){
                dp[x][j|aa]+=mod+sum[j]-last[x][j];
                dp[y][j|AA]+=mod+sum[j]-last[y][j];
                dp[x][j|aa]%=mod;
                dp[y][j|AA]%=mod;
            }
        }else{
            for (int j=0;j<=61;j++){
                int type;
                if (j>=0&&j<=25)type=aa;
                else if (j>=26&&j<=51)type=AA;
                else type=num;
                for (int k=0;k<=7;k++){
                    dp[j][k|type]+=(sum[k]-last[j][k]+mod);
                    dp[j][k|type]%=mod;
                }
            }
        }
        for (int j=0;j<=7;j++)sum[j]=0;
        for (int j=0;j<=61;j++){
            for (int k=0;k<=7;k++){
                sum[k]+=dp[j][k];
                sum[k]%=mod;
                last[j][k]=dp[j][k];
            }
        }
        // for (int i=0;i<=61;i++){
        //     for (int j=0;j<=7;j++){
        //         cout <<dp[i][j]<<" ";
        //     }
        //     cout <<endl;
        // }
        // cout <<"_______"<<endl;
        // for (int j=0;j<=7;j++)cout <<sum[j]<<" ";
        // cout <<endl;
        // cout <<"_______"<<endl;
    }
    cout <<((sum[7]%mod)+mod)%mod<<endl;
}
