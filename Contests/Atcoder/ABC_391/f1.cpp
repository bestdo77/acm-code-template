#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=1e6+10;
#define tii tuple<int,int,int,int>
int a[N],b[N],c[N];
bool cmp(int x,int y){
    return x>y; 
}
int cal(int x,int y,int z){
    return a[x]*b[y]+b[y]*c[z]+c[z]*a[x];
}
set<tii> st;
signed main(){
    int n,k;cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    sort(c+1,c+1+n,cmp);
    st.insert(tii{-cal(1,1,1),1,1,1});
    for(auto [val,x,y,z]:st){
        if(x+1<=n) st.insert(tii{-cal(x+1,y,z),x+1,y,z});
        if(y+1<=n) st.insert(tii{-cal(x,y+1,z),x,y+1,z});
        if(z+1<=n) st.insert(tii{-cal(x,y,z+1),x,y,z+1});
        cnt++;
        if(cnt==k){
           cout<<-val<<endl;
           break; 
        }
    }
    return 0;
}