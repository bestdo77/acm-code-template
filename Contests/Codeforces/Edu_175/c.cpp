#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
string s;
int n,k;
int a[N];
int RR[N],p;
bool check(int w){
    int lst=0;
    int mx=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='B'&&a[i]>w){
            cnt++;
            if(mx<=w&&lst) cnt--;
            mx=0; 
            lst=i;
        }else{
            mx=max(a[i],mx);
        }
    }
    return cnt<=k;
}
void Atomatic_AC_machine(){
    cin>>n>>k>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    p=0;
    int l=-1,r=*max_element(a+1,a+1+n)+1;
    while(l+1<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}