#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int MAXN=1e3+10;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b;cin>>a>>b;
    int cnt=0;
    for(int i=0;i<a.length();i++){
        for(int j=1;j<b.length();j++){
            if(a[i]==b[j]&&a[i+1]==b[j-1]){
                cnt++;
            }
        }
    }
    cout<<(1LL<<cnt)<<endl;
    return 0;
}