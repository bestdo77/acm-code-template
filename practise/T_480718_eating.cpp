#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
struct node{
    double x, y;
    int pos;
    bool operator<(const node& b) const{
        if(y/x==b.y/b.x) return x>b.x;
        return y/x<b.y/b.x;
    }
}a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].pos=i;
    }
    sort(a+1, a+n+1);
    cout<<a[n].pos<<endl;
    return 0;
}