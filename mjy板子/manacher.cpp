#include <bits/stdc++.h>

#define int long long
#define pii pair<int,int>
using namespace std;
typedef long long ll;

const int maxn=4e7+10;

int d[maxn];

signed main(){
    string s;
    cin>>s;
    string t(2*s.size()+2,'1');
    //改造串
    t[0]='$';//哨兵
    int n=s.size(),k=0;
    t[++k]='#';
    for(int i=0;i<n;i++){
        t[++k]=s[i];
        t[++k]='#';
    }
    //进入马拉车
    d[1]=1;
    for(int i=2,l,r=1;i<t.size();i++){
        if(i<=r) d[i] = min(d[r - i + l],r - i + 1);
        while(t[i - d[i]] == t[i + d[i]]) d[i]++;
        if(i + d[i] - 1 > r)  l = i - d[i] + 1,r = i + d[i] - 1;
    }
}