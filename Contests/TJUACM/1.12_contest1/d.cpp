#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct node{
    int x,y,z;
};
node a[N];
bool cmp1(node a,node b){
    return a.x+a.y+a.z<b.x+b.y+b.z;
}
bool cmp2(node a,node b){
    return a.x+a.y-a.z<b.x+b.y-b.z;
}
bool cmp3(node a,node b){
    return a.x-a.y+a.z<b.x-b.y+b.z;
}
bool cmp4(node a,node b){
    return -a.x+a.y+a.z<-b.x+b.y+b.z;
}
bool cmp5(node a,node b){
    return a.x-a.y-a.z<b.x-b.y-b.z;
}
bool cmp6(node a,node b){
    return -a.x+a.y-a.z<-b.x+b.y-b.z;
}
bool cmp7(node a,node b){
    return -a.x-a.y+a.z<-b.x-b.y+b.z;
}
bool cmp8(node a,node b){
    return -a.x-a.y-a.z<-b.x-b.y-b.z;
}
void Atomatic_AC_machine(){
   int x=0,y=0,z=0;
   int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    int ans=0;
    sort(a+1,a+1+n,cmp1);
    x=0,y=0,z=0;
    for(int i=n-m+1;i<=n;i++){
        x+=a[i].x,y+=a[i].y,z+=a[i].z;
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
    sort(a+1,a+1+n,cmp2);
    x=0,y=0,z=0;
    for(int i=n-m+1;i<=n;i++){
        x+=a[i].x,y+=a[i].y,z+=a[i].z;
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
    sort(a+1,a+1+n,cmp3);
    x=0,y=0,z=0;
    for(int i=n-m+1;i<=n;i++){
        x+=a[i].x,y+=a[i].y,z+=a[i].z;
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
    sort(a+1,a+1+n,cmp4);
    x=0,y=0,z=0;
    for(int i=n-m+1;i<=n;i++){
        x+=a[i].x,y+=a[i].y,z+=a[i].z;
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
    sort(a+1,a+1+n,cmp5);
    x=0,y=0,z=0;
    for(int i=n-m+1;i<=n;i++){
        x+=a[i].x,y+=a[i].y,z+=a[i].z;
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
    sort(a+1,a+1+n,cmp6);
    x=0,y=0,z=0;
    for(int i=n-m+1;i<=n;i++){
        x+=a[i].x,y+=a[i].y,z+=a[i].z;
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
    sort(a+1,a+1+n,cmp7);
    x=0,y=0,z=0;
    for(int i=n-m+1;i<=n;i++){
        x+=a[i].x,y+=a[i].y,z+=a[i].z;
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
    sort(a+1,a+1+n,cmp8);
    x=0,y=0,z=0;
    for(int i=n-m+1;i<=n;i++){
        x+=a[i].x,y+=a[i].y,z+=a[i].z;
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}