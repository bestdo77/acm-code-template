#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
vector<int> G[N];
struct node{
    int x,pos;
}a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].pos=i;
    }
    vector<int> ans(n+1,0);
    stack<node> st;
    st.push(node{inf,n+1});
    for(int i=n;i>=1;i--){
        ans[i]+=st.size()-1;
        while(!st.empty()&&a[i].x>=st.top().x) st.pop();
        st.push(a[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}