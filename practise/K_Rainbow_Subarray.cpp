#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
multiset<int> q1;
multiset<int,greater<int>> q2;
int len;
int lsum,rsum;
void restruct(){
    int k=(len/2)+1;
    while(q2.size()>k){
        int e=*q2.rbegin();
        q1.insert(*q2.rbegin()),q2.erase(--q2.rbegin().base());
        lsum+=e,rsum-=e;
    }
	while(q2.size()<k){
        int e=*q1.rbegin();
        q2.insert(*q1.rbegin()),q1.erase(--q1.rbegin().base());
        lsum-=e,rsum+=e;
    }
}
void insert(int x){
    len++;
    if(q2.empty()||x>=*q2.rbegin()) q2.insert(x);
    else q1.insert(x);
    restruct();
}
int qmid(){
    return *q2.rbegin();
}
void del(int x){
    len--;
    auto l=q1.lower_bound(x);
    auto r=q2.lower_bound(x);
    if(l!=q1.end()){
        q1.erase(l);
    }else if(r!=q2.end()){
        q2.erase(r);
    }else{
        assert(0);
    }
    restruct();
}
void clear(){
    len=0;
    q1.clear();
    q2.clear();
}
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        a[i]-=i;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    int ans=0,l=0,sum=0;
    for(int i=1;i<=n;i++){
        insert(a[i]);
        while(sum>k&&l<=i){
            del(a[l]);
            l++;
        }
        ans=max(i-l+1,ans);
    }
    cout<<ans<<endl;
    clear();
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}