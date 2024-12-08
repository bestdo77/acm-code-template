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
    int x,y,z,w;
    cin>>x>>y>>z>>w;
    int flag=0;
    for(int i=1;i<=1e4;i++){
        if(x==z*i&&y==w*i){
            flag=i;
            break;
        }
    }
    if(flag) cout<<flag<<endl;
    else cout<<-1<<endl;
    return 0;
}