#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
int prey[N],prez[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        prey[i]=prey[i-1],prez[i]=prez[i-1];
        if(s[i]=='(') prez[i]++;
        else if(s[i]==')') prey[i]++;
    }
    int z=0,y=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='_'){
            if(z+prez[i]==y+prey[i]) s[i]='(',z++;
            else s[i]=')',y++;
        }
    }
    stack<int> st;
    // cout<<s<<endl;
    while(!st.empty()) st.pop();
    int ans=0;
    // int tmp=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            ans+=i-st.top();
            st.pop();
        }
    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}