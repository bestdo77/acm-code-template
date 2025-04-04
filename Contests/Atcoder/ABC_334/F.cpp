#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<double, int>
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

struct point{
    int x,y;
}a[N];
double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cost[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=0;i<=n;i++){
        int x,y;cin>>x>>y;
        a[i]=point{x,y};
    }
    for(int i=1;i<=n;i++){
        cost[i]=dis(a[i],a[0])+dis(a[i+1],a[0])-dis(a[i],a[i+1]);
    }
    cost[n]=dis(a[n],a[0]);
    double ans=0;
    for(int i=1;i<=n;i++){
        ans+=dis(a[i],a[i-1]);
    }
    db(ans)
    cendl
    vector<double> dp(n+1,inf);
    dp[0]=0;
    dp[1]=cost[1];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(make_pair(dp[1],1));
    pq.push(make_pair(dp[0],0));
    for(int i=2;i<=n;i++){
        while(true){
            auto [u,v]=pq.top();
            if(i-v>k){
                pq.pop();
            }else break;
        }
        dp[i]=pq.top().first+cost[i];
        pq.push(make_pair(dp[i],i));
    }
    pa(dp);
    cout<<fixed<<setprecision(10)<<(dp[n]+ans)<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}