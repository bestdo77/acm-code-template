#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
// #define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
void solve(){
    int l=0,r=1000;
    int x;
    while(l+1<r){
        int mid=(l+r)>>1;
        cout<<"? "<<mid<<" "<<1<<endl;
        cin>>x;
        if(x==mid+1) r=mid;
        else l=mid;
    }
    cout<<"! "<<l+1<<endl;
}   
signed main(){
    cout<<log2(1000)/log2(3)<<endl;
    return 0;
}