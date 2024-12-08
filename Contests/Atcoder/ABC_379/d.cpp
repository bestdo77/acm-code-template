#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=5e7+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N];
int l=1,r=0,tim=0;
bool check(int x,int h){
    // cout<<"tim "<<tim<<" "<<x<<" "<<a[x]<<endl;
    return (tim-a[x]>=h);
}
void Atomatic_AC_machine(){
    int q;cin>>q;
    while(q--){
        int op;cin>>op;
        if(op==1){
            a[++r]=tim;
        }else if(op==2){
            int v;cin>>v;
            tim+=v;
        }else{
            int h;cin>>h;
            int ll=l-1,rr=r+1;
            while(ll+1<rr){
                int mid=ll+rr>>1;
                if(check(mid,h)) ll=mid;
                else rr=mid;
            }
            cout<<ll-l+1<<endl;
            l=ll+1;
            // cout<<l<<" "<<r<<endl;
        }
    }
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