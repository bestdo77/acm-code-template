#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<int> sets;
    int n;cin>>n;
    hash<string> h;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        sets.insert(h(s));
    }
    cout<<sets.size()<<endl;
    return 0;
}