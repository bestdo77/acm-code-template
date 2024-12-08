#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int vis1[510000],vis2[510000];
int vis1a[510000],p1a;
int vis1c[510000],p1c;
int vis2a[510000],p2a;
int vis2c[510000],p2c;
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
        string s11,s22;
        int len1=s1.size(),len2=s2.size();
        s1=" "+s1;s2=" "+s2;
       	for(int i=1;i<=n;i++){
            if(s1[i]!='b'){
            	s11+=s1[i];
                if(s1[i]=='a') vis1a[++p1a]=i;
                if(s1[i]=='v') vis1c[++p1c]=i;
            }
            
            if(s2[i]!=b){
                s22+=s2[i];
                if(s2[i]=='a') vis2a[++p2a]=i;
                if(s2[i]=='v') vis2c[++p2c]=i;
            }
        }

        if(s11!=s22) cout<<"NO"<<endl;
        else{
            for(int i=1;i<=p1c;i++){
                if(vis1c[i]>vis2c[i]) flag=0;
            }
            for(int i=1;i<=p1a;i++){
                if(vis1a[i]<vis2a[i]) flag=0;
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        memset(vis1,0,sizeof vis1);
        memset(vis2,0,sizeof vis2);
        memset(vis1a,0,sizeof vis1a);
        memset(vis1c,0,sizeof vis1c);
        memset(vis2a,0,sizeof vis2a);

        memset(vis2c,0,sizeof vis2c);
        p1a=p1c=0;
        p2a=p2c=0;
        
    }
    return 0;
}