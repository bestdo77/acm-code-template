#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
vector<int> a;
vector<array<int,element>> v;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,r,l;cin>>n>>r>>l;
        int cnt=1;
        for(int i=1;i<l;i++){
            if((l-1)%2==0){
                if((cnt%2)==0) cout<<"-1 ";
                else cout<<"1 ";
                cnt++;
            }else{
                if(cnt%2) cout<<"-1 ";
                else cout<<"1 ";
                cnt++;
            }
        }
        for(int i=l;i<=r;i++){
            cout<<"1 ";
        }
        cnt=1;
        for(int i=r+1;i<=n;i++){
            if(cnt%2==0) cout<<"1 ";
            else cout<<"-1 ";
            cnt++;
        }
        cout<<endl;
    }
    return 0;
}