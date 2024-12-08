#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;

int n,q,m,sumf;
vector <pair<int,int> > qes;

const int maxn =4e5+ 10;
int a[maxn];
int niq[maxn];
int tres[maxn],tren[maxn];
int lowbit(int a){
    return a&(-a);
}

void add(int x,int d,int *tre){
    while(x<maxn){
        tre[x]+=d;
        x+=lowbit(x);
    }
}

ll getsum(int x,int *tre){
    ll ans = 0;
    while(x>0)
    {
        ans+=tre[x];
        x-=lowbit(x);
    }
    return ans;
}

void solve(){
    for(int i = 0;i<q;i++){
        int x = qes[i].first;
        int v = qes[i].second;
        if(a[x] > 0){
            int pos = lower_bound(niq+1,niq+1+m,a[x]) - niq;
            add(pos,-a[x],tres);
            add(pos,-1,tren);
            if(v<=0){
                sumf += v;
            }
            else{
                pos = lower_bound(niq+1,niq+1+m,v) - niq;
                add(pos,v,tres);
                add(pos,1,tren);
            }
        }
        else{
            sumf -= a[x];
            if(v > 0){
                int pos = lower_bound(niq+1,niq+1+m,v) - niq;
                add(pos,v,tres);
                add(pos,1,tren);
            }
            else{
                sumf += v;
            }
        }
        a[x] = v;
        ;

        int l = 1,r=m;
        int pos = 1;
        while(l<=r){
            int mid = l + r >> 1;
            if(getsum(mid-1,tres) > -sumf){
                r = mid-1;
            }
            else{
                pos = mid;
                l = mid + 1;
            }
        }
        //cout<<pos<<endl;
        int ad = 0;
        l = 0,r = getsum(pos,tren) - getsum(pos-1,tren);
        while(l<=r){
            int mid = l + r >> 1;
            if(niq[pos]*mid + getsum(pos-1,tres) > -sumf){
                r = mid -1;
            }
            else{
                ad = mid;
                l = mid + 1;
            }
        }
        //cout << ad<<endl;
        int ans = getsum(pos - 1,tren) + ad ;
        cout<<ans+1<<endl;
        //cout<<endl;
    }
}


signed main(){
    cin>>n>>q;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i]<=0) {
            sumf+=a[i];
        }
        else{
            niq[++m] = a[i];
        }
    }
    
    for(int i = 1;i <= q;i++){
        int x, v;
        cin>>x>>v;
        qes.push_back(make_pair(x,v));
        if(v>0){
            niq[++m] = v;
        }
    }
    sort(niq+1,niq+1+m);
    //for(int i = 1;i<=6;i++) cout<<niq[i]<<" ";
    //cout<<endl;
    m = unique(niq + 1,niq + 1 + m) - niq - 1;
    //cout<<m<<endl;
    //for(int i = 1;i<=6;i++) cout<<niq[i]<<" ";
    //cout<<endl;
    for(int i = 1;i<=n;i++){
        if(a[i]>0){
            int pos = lower_bound(niq+1,niq+1+m,a[i]) - niq ;
            add(pos,a[i],tres);
            add(pos,1,tren);
        }
    }
    //cout<<m<<endl;
    solve();
}