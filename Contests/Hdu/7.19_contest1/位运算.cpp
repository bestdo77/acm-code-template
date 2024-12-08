#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    int cnt=0;
    for(int i=0;i<(1<<k);i++)
        for(int j=0;j<(1<<k);j++)
            for(int l=0;l<(1<<k);l++)
                for(int r=0;r<(1<<k);r++){
                    if((((i&j)^l)|r)==n) cnt++;
                }
                cout<<cnt<<endl;
    return 0;
}