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
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        s=" "+s;
        int n;cin>>n;
        int cnt=0;
        string res="respect";
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        a[0]=0,a[n+1]=s.length();
        for(int i=0;i<=n;i++){
            string st=s.substr(a[i],a[i+1]-a[i]+1);
            if(st.find(res)!=string::npos){
                cnt++;
            }
            // cout<<st<<endl;         
        }
        cout<<cnt<<endl;   
    }
    return 0;
}