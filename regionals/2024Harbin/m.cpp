#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn = 1e5+10;
int a[maxn];
set<int> st;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                st.insert(i);
                st.insert(n/i);
                // cout<<i<<" "<<n%i<<endl;
            }
        }
        int last=1;
        int ans=1;
        for(auto it:st){
            if(it==1) continue;
            ans+=(n/last)*(it-last);
            last=it;
            // cout<<it<<endl;
        }
        cout<<ans<<endl;
        st.clear();
    }

    
}