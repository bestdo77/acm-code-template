#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=3e7+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int d[N];
char t[N],s[N];
void manacher(char *s,int n){
    d[1]=1;
    for(int i=2,l,r=1;i<=n;i++){
        if(l<=r) d[i]=min(d[l+r-i],r-i+1);
        while(t[i-d[i]]==t[i+d[i]]) d[i]++;
        if(d[i]>r-i+1) l=i-d[i]+1,r=i+d[i]-1;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    scanf("%s",s+1);
    int len=strlen(s+1),k=0;
    t[0]='$',t[++k]='#';
    for(int i=1;i<=len;i++){
        t[++k]=s[i],t[++k]='#';
    }
    manacher(s,k);
    cout<<*max_element(d+1,d+1+k)-1<<endl; 
    return 0;
}