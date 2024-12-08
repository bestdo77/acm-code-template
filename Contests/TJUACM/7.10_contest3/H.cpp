#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[510000];
int vis[510000][3];//a,b,c表示某一位已经匹配
const int MAXN=1e3+10;
string s1,s2;
bool flag;
void abcswap(int x,int y){
    if(s1[x]<s1[y]){
        swap(s1[x],s1[y]);
    }else flag=0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        flag=1;
        cin>>s1>>s2;
        int len1=s1.size(),len2=s2.size();
        s1=" "+s1;s2=" "+s2;
        bool flag=1;
        for(int i=1;i<=len2;i++){
            if(s2[i]=='b'){//如果匹配串是b
                for(int j=i;j<=len2;j++){//去模式串找b
                    if(s1[j]=='b'){
                         while(i!=j){
                            abcswap(j-1,j);
                            j--;       
                        }
                        break;
                    } 
                }
            }
            if(!flag) break; 
        }//枚举c
        for(int i=1;i<=len2;i++){
            if(s2[i]=='c'){//如果匹配串是c
                for(int j=i;j<=len1;j++){//去模式串找c
                    if(s1[j]=='c'){
                         while(i!=j){
                            abcswap(j-1,j);
                            j--;       
                        }
                        break;
                    }
                }
            }
            if(!flag) break; 
        }//枚举c
       // cout<<s1<<endl;
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        
        //cout<<s1<<endl;
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        if(s1==s2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}