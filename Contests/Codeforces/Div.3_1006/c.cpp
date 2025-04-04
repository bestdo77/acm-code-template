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
int pre[N];
void Atomatic_AC_machine(){
    vector<int> ans;
    int n,k;cin>>n>>k;
    bool flag=0;
    for(int i=0;i<=min(n-2,(int)3e5);i++){
        db((k|pre[i]))
        cendl
        if((k|pre[i])!=k){
            for(int j=0;j<=i-1;j++){
                ans.push_back(j);
                flag=1;
            }
            break;
        }
    }
    if(!flag){
        for(int i=0;i<=n-2;i++){
            ans.push_back(i);
        }
    }
    if(pre[n-1]==k){
        ans.push_back(n-1);
    }
    while(ans.size()<n){
        ans.push_back(k);
    }
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    for(int i=1;i<=300000;i++){
        pre[i]=i|pre[i-1];
    }
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}