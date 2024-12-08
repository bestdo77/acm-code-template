#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int inf=0x3f3f3f3f3f3f3f3f;
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >>n;
       // cout <<"n"<<n<<endl;
        int sum=0;
        int flag1=1;
        int minn=inf;
        int flag2=1;
        if (n==1){
            int tem;
            cin >>tem;
            cout <<tem<<endl;
            continue;
        }
        for (int i=1;i<=n;i++){
            int tem;
            cin >>tem;
            sum+=abs(tem);
            if (tem>=0)flag1=0;
            if (tem<=0)flag2=0;
            minn=min(minn,abs(tem));
        }
        if (!flag1&&!flag2)cout <<sum<<endl;
        else{
            cout <<sum-minn-minn<<endl;
        }
    }
}