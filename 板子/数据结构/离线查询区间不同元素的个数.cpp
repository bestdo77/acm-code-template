#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif
#define all(x) x.begin(),x.end()

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
struct Fenwick{
    int n;
    vector<int> a;
    Fenwick(int n_ = 0){
        n=n_;
        a.assign(n+1,0);
    }
    void add(int x,int v){
        for(int i=x;i<=n;i+=(i&-i)){
            a[i]+=v;            
        }
    }
    int sum(int x){
        int ans=0;
        for(int i=x;i>0;i-=i&-i){
            ans+=a[i];
        }
        return ans;
    }
};
struct query{
    int l, r, id;
};
void Atomatic_AC_machine(){
    Fenwick f(N);
    int n;cin>>n;
    vector<int> a(n+1),lst(N+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int m;cin>>m;
    vector<query> op(m);
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        op[i]=query{l,r,i};
    }
    sort(all(op),[&](query x,query y){return (x.r==y.r) ? x.l<y.l : x.r<y.r; });
    int nowr=0;
    for(auto [l,r,i]:op){
        while(nowr<r){
            ++nowr;
            int x=a[nowr];
            if(lst[x]) f.add(lst[x],-1);
            f.add(nowr,1);
            lst[x]=nowr;
        }
        ans[i]=f.sum(r)-f.sum(l-1);
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
} 