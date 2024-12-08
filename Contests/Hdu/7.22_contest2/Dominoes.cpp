#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define F .first
#define S .second
#define P .push_back
pii a[200005];
vector<pii> ans;
int n,ct,p,cnt,x,y;  
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(x!=y){
            a[++cnt]={x,y};
            if(a[cnt]F==a[cnt-1]S) swap(a[cnt]F,a[cnt]S);              
        }else{
            if(!ct||p==x) p=x,ct++;
            else{
                if(a[cnt]S==x) a[++cnt]={p,p},a[++cnt]={x,x};
                else a[++cnt]={x,x},a[++cnt]={p,p};
                ct--;
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        if(ct&&a[i-1]S!=p&&a[i]F!=p) ans.push_back({p,p}),ct--;
        ans.push_back(a[i]);
    }
    if(ct&&a[cnt]S!=p) ans.push_back({p,p}),ct--;
    if(ct)cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        for(auto [a,b]:ans){
            cout<<a<<" "<<b<<endl;
        }
    } 
}