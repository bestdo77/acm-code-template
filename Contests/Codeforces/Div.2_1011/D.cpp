#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<i64,i64>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;

#define endl '\n'
#define all(x) x.begin(),x.end()

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
const i64 mod=1e9+7;
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    vector<int> a(n,0);
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    i64 cost=0,ans=0;
    for(int i=n-1;i>=0;i--){
        if(k+1+cost<=n-i){
            pq.push(a[i]);    
            ans+=a[i];
            cost+=k+1;
        }else if(pq.size()){
            auto x=pq.top();
            if(a[i]>x){
                pq.pop();
                pq.push(a[i]);
                ans=ans-x+a[i];
            }
        }    
    }
    cout<<ans<<endl;
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