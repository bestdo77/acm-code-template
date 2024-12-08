#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
struct node{
    int pos,yufa,num;
    bool operator < (const node &a) const{
        if(yufa*num==a.yufa*a.num) return a.pos<pos;
        return yufa*num<a.yufa*a.num;
    }
}a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].yufa;
        a[i].pos=i;
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[x].num++;
    }
    sort(a+1,a+m+1);
    cout<<a[m].pos<<endl;
    return 0;
}