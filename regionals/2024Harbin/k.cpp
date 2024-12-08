#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5+10;
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
int re[N];
pii w[N];//val&id;
pii a[N];//ins;
int n,m;
int precnt[N],preval[N];//pre of w;
bool cmp(pii x,pii y){
    return x>y;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int ans=0,lsum=0;
    int resop=0;
    for(int i=1;i<=n;i++){
        int ww,l,r;cin>>ww>>l>>r;
        w[i].first=ww;
        w[i].second=i;
        a[i].first=l;
        a[i].second=r;
        re[i]=r-l;
        
        m-=l;
        lsum+=l*w[i].first;
    }
    resop=m;
    // cerr<<lsum<<" "<<resop<<endl;
    sort(w+1,w+1+n,cmp);
    for(int i=1;i<=n;i++){
        precnt[i]=precnt[i-1]+re[w[i].second];
        preval[i]=preval[i-1]+re[w[i].second]*w[i].first;
    }
    for(int i=1;i<=n;i++){
        //opr 1
        ans=max(ans,lsum+resop*w[i].first);
        //opr 2
        int anss=0;
        
        int tmp=precnt[i];
        precnt[i]=inf;

        int cnt=a[w[i].second].first+resop;//least of id;
        int pos=(upper_bound(precnt+1,precnt+1+n,cnt)-precnt)-1;//pos of ope
        cnt-=precnt[pos];
        anss+=preval[pos];
        anss+=cnt*w[pos+1].first;
        
        precnt[i]=tmp;
        anss+=lsum-w[i].first*a[w[i].second].first;
        // cerr<<"pos: "<<pos<<"anss: "<<anss<<endl;
        ans=max(ans,anss);
    }
    cout<<ans<<endl;
}
/*
5 17
2 3 4
6 1 5
8 2 4
4 3 3
7 5 5
*/