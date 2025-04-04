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
int a[N];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    priority_queue<int> pq1;
    int sum=0;
    int cnt=0;
    for(int i=m;i>1;i--){
        sum+=a[i];
        if(a[i]>0) pq1.push(a[i]);
        while(sum>0&&pq1.size()){
            sum-=2*pq1.top();
            pq1.pop();
            cnt++;
        }
    }
    sum=0;
    for(int i=m+1;i<=n;i++){
        sum+=a[i];
        if(a[i]<0) pq.push(a[i]);
        while(sum<0&&pq.size()){
            sum-=2*pq.top();
            pq.pop();
            cnt++;
        }
    }
    cout<<cnt<<endl;
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