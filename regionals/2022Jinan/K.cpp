#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void solve(){
    set<int> st;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(st.lower_bound(x+1)!=st.end()&&*st.lower_bound(x+1)==x+1){
            st.erase(x+1);
            st.insert(x);
            // cout<<1<<endl;
        }else{
            st.insert(x);
        }
    }
    cout<<st.size()<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}