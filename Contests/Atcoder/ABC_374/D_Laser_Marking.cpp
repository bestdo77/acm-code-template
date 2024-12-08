#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct node{
    double x,y;
};
pair<node,node> a[N];
double len[N];
double dist(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void Atomatic_AC_machine(){
    int n,s,t;
    cin>>n>>s>>t;
    node ori={0,0};
    for(int i=1;i<=n;i++){
        cin>>a[i].first.x>>a[i].first.y>>a[i].second.x>>a[i].second.y;
        len[i]=dist(a[i].first,a[i].second);
    }
    int id[10];
    for(int i=1;i<=n;i++){
        id[i]=i;
    }
    double ans=inf;
    do{
        double tim1=inf;
        for(int i=0;i<(1<<n);i++){
            node last=ori;
            double tim=0;
            for(int j=1;j<=n;j++){
                int ii=id[j];
                int p=1<<(j-1);
                if(i&p){
                    tim+=dist(a[ii].second,last)/s;
                    tim+=len[ii]/t;
                    last=a[ii].first;
                }else{
                    tim+=dist(a[ii].first,last)/s;
                    tim+=len[ii]/t;
                    last=a[ii].second;
                }
            }
            tim1=min(tim1,tim);
        }
        ans=min(ans,tim1);
        // for(int i=1;i<=n;i++){
        //     cout<<id[i]<<" ";
        // }cout<<endl;
    }while(next_permutation(id+1,id+1+n));
    cout<<fixed<<setprecision(20)<<ans<<endl;
}


signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}